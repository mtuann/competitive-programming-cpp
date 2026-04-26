// Template: Skiplist Ordered Set
// Signal: one probabilistically balanced ordered dictionary where search,
// insert, and erase-one are the whole lesson.
// Assumes: set semantics; duplicate inserts are ignored.
// Exposes: SkiplistOrderedSet with contains(), insert(), and erase_one().
// Complexity: expected O(log n) per operation.
// Main trap: corrupting update[] during insert/erase or forgetting that the
// guarantees are expected-time.
// Links:
//   Topic: topics/data-structures/skip-lists/README.md
//   Note: practice/ladders/data-structures/skip-lists/skiplistdictionary.md

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct SkiplistOrderedSet {
    static constexpr int MAX_LEVEL = 31;

    struct Node {
        int key = 0;
        vector<Node*> next;
        Node(int key, int level) : key(key), next(level + 1, nullptr) {}
    };

    Node* head = new Node(0, MAX_LEVEL);
    int current_level = 0;

    ~SkiplistOrderedSet() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nxt = cur->next[0];
            delete cur;
            cur = nxt;
        }
    }

    bool contains(int key) const {
        Node* cur = head;
        for (int level = current_level; level >= 0; level--) {
            while (cur->next[level] != nullptr && cur->next[level]->key < key) {
                cur = cur->next[level];
            }
        }
        cur = cur->next[0];
        return cur != nullptr && cur->key == key;
    }

    bool insert(int key) {
        Node* update[MAX_LEVEL + 1];
        Node* cur = head;
        for (int level = current_level; level >= 0; level--) {
            while (cur->next[level] != nullptr && cur->next[level]->key < key) {
                cur = cur->next[level];
            }
            update[level] = cur;
        }
        cur = cur->next[0];
        if (cur != nullptr && cur->key == key) {
            return false;
        }

        int node_level = random_level();
        if (node_level > current_level) {
            for (int level = current_level + 1; level <= node_level; level++) {
                update[level] = head;
            }
            current_level = node_level;
        }

        Node* node = new Node(key, node_level);
        for (int level = 0; level <= node_level; level++) {
            node->next[level] = update[level]->next[level];
            update[level]->next[level] = node;
        }
        return true;
    }

    bool erase_one(int key) {
        Node* update[MAX_LEVEL + 1];
        Node* cur = head;
        for (int level = current_level; level >= 0; level--) {
            while (cur->next[level] != nullptr && cur->next[level]->key < key) {
                cur = cur->next[level];
            }
            update[level] = cur;
        }
        cur = cur->next[0];
        if (cur == nullptr || cur->key != key) {
            return false;
        }

        for (int level = 0; level <= current_level; level++) {
            if (update[level]->next[level] != cur) {
                break;
            }
            update[level]->next[level] = cur->next[level];
        }
        delete cur;
        while (current_level > 0 && head->next[current_level] == nullptr) {
            current_level--;
        }
        return true;
    }

private:
    static uint64_t next_random() {
        static uint64_t state = 0x9e3779b97f4a7c15ULL;
        state += 0x9e3779b97f4a7c15ULL;
        uint64_t z = state;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }

    static int random_level() {
        int level = 0;
        while (level < MAX_LEVEL && (next_random() & 1ULL)) {
            level++;
        }
        return level;
    }
};

int main() {
    SkiplistOrderedSet st;
    st.insert(10);
    st.insert(5);
    st.insert(20);
    cout << st.contains(10) << '\n';
    cout << st.contains(7) << '\n';
    st.erase_one(10);
    cout << st.contains(10) << '\n';
    return 0;
}
