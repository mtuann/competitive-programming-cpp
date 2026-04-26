// Template: X-Fast Trie
// Signal: one bounded-universe ordered set where predecessor/successor are the
// whole lesson, not xor-max or rank/k-th.
// Assumes: keys are unique non-negative integers in [0, 2^31).
// Exposes: XFastTrieSet with contains(), insert(), erase_one(),
// predecessor_strict(), and successor_strict().
// Complexity: search / predecessor / successor O(log w), updates O(w).
// Main trap: forgetting that this is an x-fast trie only; y-fast is the
// bucketed refinement, not this starter.
// Links:
//   Topic: topics/data-structures/x-fast-y-fast-tries/README.md
//   Note: practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct XFastTrieSet {
    static constexpr int BITS = 31;

    struct Node {
        Node* child[2] = {nullptr, nullptr};
        Node* parent = nullptr;
        Node* jump = nullptr;
        Node* min_leaf = nullptr;
        Node* max_leaf = nullptr;
        Node* prev = nullptr;
        Node* next = nullptr;
        uint32_t key = 0;
        bool is_leaf = false;

        Node(uint32_t key, bool is_leaf) : key(key), is_leaf(is_leaf) {
            if (is_leaf) {
                min_leaf = this;
                max_leaf = this;
            }
        }
    };

    vector<unordered_map<uint32_t, Node*>> level_maps;
    Node* root = new Node(0, false);
    int size_ = 0;

    XFastTrieSet() : level_maps(BITS + 1) {
        level_maps[0][0] = root;
        pull(root);
    }

    ~XFastTrieSet() { destroy(root); }

    bool contains(uint32_t key) const { return level_maps[BITS].count(key) != 0; }

    bool insert(uint32_t key) {
        if (contains(key)) {
            return false;
        }

        Node* succ = lower_bound_leaf(key);
        Node* pred = succ != nullptr ? succ->prev : root->max_leaf;

        Node* leaf = new Node(key, true);
        leaf->prev = pred;
        leaf->next = succ;
        if (pred != nullptr) {
            pred->next = leaf;
        }
        if (succ != nullptr) {
            succ->prev = leaf;
        }

        Node* cur = root;
        for (int depth = 1; depth <= BITS; depth++) {
            uint32_t pref = prefix(key, depth);
            int bit = next_bit(key, depth - 1);
            auto it = level_maps[depth].find(pref);
            if (it == level_maps[depth].end()) {
                Node* node = depth == BITS ? leaf : new Node(0, false);
                node->parent = cur;
                cur->child[bit] = node;
                level_maps[depth][pref] = node;
                cur = node;
            } else {
                cur = it->second;
            }
        }

        for (Node* u = leaf->parent; u != nullptr; u = u->parent) {
            pull(u);
        }
        size_++;
        return true;
    }

    bool erase_one(uint32_t key) {
        auto it = level_maps[BITS].find(key);
        if (it == level_maps[BITS].end()) {
            return false;
        }

        Node* leaf = it->second;
        if (leaf->prev != nullptr) {
            leaf->prev->next = leaf->next;
        }
        if (leaf->next != nullptr) {
            leaf->next->prev = leaf->prev;
        }

        Node* cur = leaf;
        int depth = BITS;
        while (depth > 0) {
            Node* parent = cur->parent;
            int bit = next_bit(key, depth - 1);
            if (parent->child[bit] == cur) {
                parent->child[bit] = nullptr;
            }
            level_maps[depth].erase(prefix(key, depth));
            delete cur;
            cur = parent;
            depth--;
            if (cur == root || cur->child[0] != nullptr || cur->child[1] != nullptr) {
                break;
            }
        }

        for (Node* u = cur; u != nullptr; u = u->parent) {
            pull(u);
        }
        size_--;
        return true;
    }

    bool predecessor_strict(uint32_t key, uint32_t& out) const {
        Node* node = predecessor_leaf(key);
        if (node == nullptr) {
            return false;
        }
        out = node->key;
        return true;
    }

    bool successor_strict(uint32_t key, uint32_t& out) const {
        Node* node = lower_bound_leaf(key);
        if (node != nullptr && node->key == key) {
            node = node->next;
        }
        if (node == nullptr) {
            return false;
        }
        out = node->key;
        return true;
    }

private:
    static uint32_t prefix(uint32_t key, int len) {
        if (len == 0) {
            return 0;
        }
        return key >> (BITS - len);
    }

    static int next_bit(uint32_t key, int consumed) {
        return int((key >> (BITS - 1 - consumed)) & 1U);
    }

    void pull(Node* u) {
        if (u->is_leaf) {
            u->min_leaf = u;
            u->max_leaf = u;
            u->jump = nullptr;
            return;
        }
        Node* left = u->child[0];
        Node* right = u->child[1];
        u->min_leaf = left != nullptr ? left->min_leaf : (right != nullptr ? right->min_leaf : nullptr);
        u->max_leaf = right != nullptr ? right->max_leaf : (left != nullptr ? left->max_leaf : nullptr);
        if (left != nullptr && right != nullptr) {
            u->jump = nullptr;
        } else if (left != nullptr) {
            u->jump = left->max_leaf;
        } else if (right != nullptr) {
            u->jump = right->min_leaf;
        } else {
            u->jump = nullptr;
        }
    }

    int deepest_prefix(uint32_t key) const {
        int lo = 0;
        int hi = BITS + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (level_maps[mid].count(prefix(key, mid)) != 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    Node* lower_bound_leaf(uint32_t key) const {
        if (size_ == 0) {
            return nullptr;
        }
        auto it = level_maps[BITS].find(key);
        if (it != level_maps[BITS].end()) {
            return it->second;
        }

        int depth = deepest_prefix(key);
        Node* u = level_maps[depth].at(prefix(key, depth));
        if (depth == BITS) {
            return u;
        }

        int bit = next_bit(key, depth);
        if (bit == 0) {
            return u->jump;
        }
        Node* pred = u->jump;
        return pred != nullptr ? pred->next : nullptr;
    }

    Node* predecessor_leaf(uint32_t key) const {
        if (size_ == 0) {
            return nullptr;
        }
        auto it = level_maps[BITS].find(key);
        if (it != level_maps[BITS].end()) {
            return it->second->prev;
        }

        int depth = deepest_prefix(key);
        Node* u = level_maps[depth].at(prefix(key, depth));
        if (depth == BITS) {
            return u->prev;
        }

        int bit = next_bit(key, depth);
        if (bit == 1) {
            return u->jump;
        }
        Node* succ = u->jump;
        return succ != nullptr ? succ->prev : nullptr;
    }

    void destroy(Node* u) {
        if (u == nullptr) {
            return;
        }
        destroy(u->child[0]);
        destroy(u->child[1]);
        delete u;
    }
};

int main() {
    XFastTrieSet st;
    st.insert(10);
    st.insert(5);
    st.insert(20);
    cout << st.contains(10) << '\n';
    uint32_t value = 0;
    if (st.predecessor_strict(10, value)) {
        cout << value << '\n';
    } else {
        cout << -1 << '\n';
    }
    if (st.successor_strict(10, value)) {
        cout << value << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
