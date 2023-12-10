#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ThreadSafeQueue {
public:
    // Constructor
    ThreadSafeQueue() {}

    // Destructor
    ~ThreadSafeQueue() {}

    // Enqueue an element into the queue
    void enqueue(const T& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(value);
        lock.unlock();
        condition_.notify_one();
    }

    // Dequeue an element from the queue
    T dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        T frontValue = queue_.front();
        queue_.pop();
        return frontValue;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable condition_;
};
