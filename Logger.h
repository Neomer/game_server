//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_LOGGER_H
#define WEBSOCKETS_LOGGER_H

#include <queue>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <string_view>

class Logger
{
public:
    static Logger &getInstace();

    void log(std::thread::id threadId, std::string_view text);

    void log(std::string_view text);

private:
    Logger();

    ~Logger();

    void writeProc();

    struct Msg {
        std::thread::id ThreadId;
        std::string Text;
    };

    std::atomic_bool _run;
    std::thread _writeThread;
    std::mutex _queueMutex;
    std::queue<Msg> _messageQueue, _messageCopyQueue;
    std::condition_variable _queueCondVar;
};


#endif //WEBSOCKETS_LOGGER_H
