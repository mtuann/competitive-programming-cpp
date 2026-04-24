// Template: offline query skeleton
// Signal: events and queries can both be sorted by one monotone key, then swept once.
// Assumes: each query answer depends only on all events whose key is already eligible.
// Exposes: Event / Query structs, one sorted sweep, and answer restoration by query id.
// Complexity: O((n + q) log (n + q)) for sorting plus linear sweep work.
// Main trap: forcing this on problems whose answers depend on previous answers or online updates.
// Links:
//   Topic: topics/data-structures/offline-tricks/README.md
//   Note: practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md

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
