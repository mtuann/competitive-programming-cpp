#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct SkiplistOrderedSet {
    static constexpr int MAX_LEVEL = 31;

    struct Node {
        long long key = 0;
        vector<Node*> next;
        Node(long long key, int level) : key(key), next(level + 1, nullptr) {}
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

    bool contains(long long key) const {
        Node* cur = head;
        for (int level = current_level; level >= 0; level--) {
            while (cur->next[level] != nullptr && cur->next[level]->key < key) {
                cur = cur->next[level];
            }
        }
        cur = cur->next[0];
        return cur != nullptr && cur->key == key;
    }

    bool insert(long long key) {
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

    bool erase_one(long long key) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    SkiplistOrderedSet st;
    while (q--) {
        char op;
        long long x;
        cin >> op >> x;
        if (op == '+') {
            st.insert(x);
        } else if (op == '-') {
            st.erase_one(x);
        } else if (op == '?') {
            cout << (st.contains(x) ? 1 : 0) << '\n';
        }
    }
    return 0;
}
