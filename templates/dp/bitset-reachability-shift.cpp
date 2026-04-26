#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct DynamicBitsetReachability {
    int max_index;
    vector<uint64_t> words;

    explicit DynamicBitsetReachability(int max_index_)
        : max_index(max_index_), words((max_index_ >> 6) + 1, 0) {
        words[0] = 1ULL;  // sum 0 is reachable.
        trim_tail();
    }

    void trim_tail() {
        int used_bits = (max_index & 63) + 1;
        if (used_bits == 64) return;
        words.back() &= ((1ULL << used_bits) - 1ULL);
    }

    void or_shift_left(int shift) {
        if (shift <= 0) return;
        int whole = shift >> 6;
        int offset = shift & 63;
        for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
            uint64_t shifted = 0;
            int from = i - whole;
            if (from >= 0) {
                shifted |= words[from] << offset;
                if (offset != 0 && from - 1 >= 0) {
                    shifted |= words[from - 1] >> (64 - offset);
                }
            }
            words[i] |= shifted;
        }
        trim_tail();
    }

    bool test(int index) const {
        if (index < 0 || index > max_index) return false;
        return (words[index >> 6] >> (index & 63)) & 1ULL;
    }

    vector<int> reachable_values(int from = 1) const {
        vector<int> result;
        for (int x = max(0, from); x <= max_index; ++x) {
            if (test(x)) result.push_back(x);
        }
        return result;
    }
};

int main() {
    vector<int> weights = {2, 3, 5};
    int max_sum = 10;
    DynamicBitsetReachability reachable(max_sum);
    for (int w : weights) reachable.or_shift_left(w);

    vector<int> sums = reachable.reachable_values(1);
    for (size_t i = 0; i < sums.size(); ++i) {
        if (i) cout << ' ';
        cout << sums[i];
    }
    cout << '\n';
    return 0;
}
