#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>

template <typename T> class ThreadSafeQueue {
public:
    // Constructor with maximum size
    ThreadSafeQueue(size_t maxSize)
        : maxSize_(maxSize) {
    }

    // Destructor
    ~ThreadSafeQueue() {
    }

    // Enqueue an element into the queue
    void enqueue(const T &value) {
        std::unique_lock<std::mutex> lock(mutex_);
        conditionFull_.wait(lock, [this] { return queue_.size() < maxSize_; });
        queue_.push(value);
        lock.unlock();
        conditionEmpty_.notify_one();
    }

    // Dequeue an element from the queue
    T dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        conditionEmpty_.wait(lock, [this] { return !queue_.empty(); });
        T frontValue = queue_.front();
        queue_.pop();
        lock.unlock();
        conditionFull_.notify_one();
        return frontValue;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    // Check if the queue is full
    bool isFull() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue_.size() >= maxSize_;
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable conditionEmpty_;
    std::condition_variable conditionFull_;
    size_t maxSize_;
};
