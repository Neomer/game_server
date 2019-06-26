//
// Created by kir on 26.06.19.
//

#include <iostream>
#include <functional>
#include <iomanip>
#include "Logger.h"

Logger::Logger() :
    _run{ true },
    _writeThread{ std::bind(&Logger::writeProc, this) }
{

}

Logger::~Logger()
{

}

Logger &Logger::getInstace()
{
    static Logger instance;
    return instance;
}

void Logger::log(std::thread::id threadId, std::string_view text)
{
    std::lock_guard lock(_queueMutex);
    _messageQueue.push(Msg{ threadId, std::string{text} });
    _queueCondVar.notify_one();
}

void Logger::log(std::string_view text)
{
    log(std::this_thread::get_id(), text);
}


void Logger::writeProc()
{
    std::mutex cvMtx;
    std::unique_lock lock(cvMtx);

    while (_run.load()) {
        _queueCondVar.wait(lock);
        if (!_messageQueue.empty()) {
            std::lock_guard guard(_queueMutex);
            _messageCopyQueue.swap(_messageQueue);
        }
        while (!_messageCopyQueue.empty()) {
            auto msg = _messageCopyQueue.front();
            std::cout << '[' << std::hex << std::setw(4) << msg.ThreadId << "] " << msg.Text << std::endl;
            _messageCopyQueue.pop();
        }
    }
}
