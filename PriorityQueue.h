#pragma once
#include <queue>
#include <optional>
#include <vector>

// Optimized priority queue functionality using std::priority_queue binary heap method
struct Transition;
struct CompareTransition {
    bool operator()(const Transition& t1, const Transition& t2) const;
};

template <typename T>
class PriorityQueue {
public:
    std::optional<T> min() const {
        if (len() == 0)
            return std::nullopt;
        return m_queue.top();
    }

    std::optional<T> pop() {
        if (len() == 0)
            return std::nullopt;
        T minElement = m_queue.top();
        m_queue.pop();
        return minElement;
    }

    void append(const T& item) {
        m_queue.push(item);
    }

    size_t len() const noexcept {
        return m_queue.size();
    }

private:
    std::priority_queue<T, std::vector<T>, CompareTransition> m_queue;
};