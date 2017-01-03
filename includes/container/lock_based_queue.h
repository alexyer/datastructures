#ifndef DATASTRUCTURES_LOCK_BASED_QUEUE_H
#define DATASTRUCTURES_LOCK_BASED_QUEUE_H

#include <mutex>
#include <list>

using std::lock_guard;
using std::shared_ptr;
using std::mutex;
using std::list;

template <typename Object>
class LockBasedQueue {
    list<Object> items;
    mutex items_mutex;

public:
    const shared_ptr<Object> back() const {
        return std::make_shared<Object>(items.back());
    }

    const shared_ptr<Object> front() const {
        return std::make_shared<Object>(items.front());
    }

    bool empty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();
    }

    void push(const Object& val) {
        lock_guard<mutex> lock(items_mutex);
        items.push_back(val);
    }

    void pop() {
        lock_guard<mutex> lock(items_mutex);
        items.pop_front();
    }
};

#endif //DATASTRUCTURES_LOCK_BASED_QUEUE_H
