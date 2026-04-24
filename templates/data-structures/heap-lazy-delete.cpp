// Template: heap with lazy deletion
// Signal: heap ordering is right, but deletions happen by value instead of only at the top.
// Assumes: every erase(x) corresponds to a currently live value, and every observable read goes through top() / empty().
// Exposes: LazyMinHeap with push(x), erase(x), top(), empty().
// Complexity: O(log n) per push/erase and O(log n) amortized per discarded value during normalize().
// Main trap: reading in_heap.top() directly or erasing values that were never actually live in the heap.
// Links:
//   Topic: topics/data-structures/heaps-and-ordered-sets/README.md
//   Notebook: notebook/data-structures-cheatsheet.md

#include <functional>
#include <iostream>
#include <queue>

using namespace std;

template <class T>
struct LazyMinHeap {
    priority_queue<T, vector<T>, greater<T>> in_heap;
    priority_queue<T, vector<T>, greater<T>> deleted;

    void normalize() {
        while (!in_heap.empty() && !deleted.empty() && in_heap.top() == deleted.top()) {
            in_heap.pop();
            deleted.pop();
        }
    }

    void push(T x) {
        in_heap.push(x);
    }

    void erase(T x) {
        deleted.push(x);
    }

    T top() {
        normalize();
        return in_heap.top();
    }

    bool empty() {
        normalize();
        return in_heap.empty();
    }
};

int main() {
    LazyMinHeap<int> heap;
    heap.push(5);
    heap.push(2);
    heap.push(7);
    heap.erase(2);
    cout << heap.top() << '\n';
    return 0;
}
