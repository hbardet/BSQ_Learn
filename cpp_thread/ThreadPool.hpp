/*
** EPITECH PROJECT, 2024
** cpp_thread
** File description:
** ThreadPool
*/


#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <functional>

namespace BSQ {
    class ThreadPool {
    public:
        void Start();
        void QueueJob(const std::function<void()>& job);
        void Stop();
        bool busy();
        void waitEndQueue();

    private:
        void ThreadLoop();

        bool should_terminate = false;           // Tells threads to stop looking for jobs
        std::mutex queue_mutex;                  // Prevents data races to the job queue
        std::condition_variable mutex_condition; // Allows threads to wait on new jobs or termination 
        std::vector<std::jthread> threads;
        std::queue<std::function<void()>> jobs;
    };
}
