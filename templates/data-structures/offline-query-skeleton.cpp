// Template: offline query skeleton
// Sort events and queries by a monotone key, process once, and restore answer order.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Event {
    int key;
    int value;
};

struct Query {
    int key;
    int id;
};

int main() {
    vector<Event> events = {{1, 3}, {3, 2}, {5, 4}};
    vector<Query> queries = {{0, 0}, {3, 1}, {4, 2}, {6, 3}};
    vector<int> answer(static_cast<int>(queries.size()), 0);

    sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
        return a.key < b.key;
    });
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
        return a.key < b.key;
    });

    int ptr = 0;
    int current = 0;
    for (const Query &q : queries) {
        while (ptr < static_cast<int>(events.size()) && events[ptr].key <= q.key) {
            current += events[ptr].value;
            ++ptr;
        }
        answer[q.id] = current;
    }

    for (int x : answer) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
