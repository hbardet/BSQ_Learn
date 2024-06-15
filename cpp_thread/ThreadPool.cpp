/*
** EPITECH PROJECT, 2024
** cpp_thread
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"
#include <iostream>

void BSQ::ThreadPool::Start() {
    const uint32_t num_threads = std::jthread::hardware_concurrency();
    for (uint32_t ii = 0; ii < num_threads; ++ii) {
        threads.emplace_back(std::jthread(&ThreadPool::ThreadLoop,this));
    }
}

void BSQ::ThreadPool::ThreadLoop() {
    while (true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            mutex_condition.wait(lock, [this] {
                return !jobs.empty() || should_terminate;
            });
            if (should_terminate) {
                return;
            }
            job = jobs.front();
            jobs.pop();
        }
        job();
    }
}

void BSQ::ThreadPool::QueueJob(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        jobs.push(job);
    }
    mutex_condition.notify_one();
    // (void)job;
    // std::cout << "QueueJob" << std::endl;
}

bool BSQ::ThreadPool::busy() {
    bool poolbusy;
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        poolbusy = !jobs.empty();
    }
    return poolbusy;
}

void BSQ::ThreadPool::Stop() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        should_terminate = true;
    }
    mutex_condition.notify_all();
    for (std::jthread& active_thread : threads) {
        active_thread.join();
    }
    threads.clear();
}

void BSQ::ThreadPool::waitEndQueue() {
    while (busy()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
