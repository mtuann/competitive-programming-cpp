// Template: heap with lazy deletion using a second heap.

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
