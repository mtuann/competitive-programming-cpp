#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string build_binary_de_bruijn(int n) {
    if (n == 1) {
        return "01";
    }

    int states = 1 << (n - 1);
    int mask = states - 1;
    vector<int> next_bit(states, 0);
    vector<int> node_stack = {0};
    vector<int> in_bit_stack = {-1};
    vector<int> cycle_bits;
    cycle_bits.reserve(1 << n);

    while (!node_stack.empty()) {
        int u = node_stack.back();
        if (next_bit[u] < 2) {
            int bit = next_bit[u]++;
            int v = ((u << 1) & mask) | bit;
            node_stack.push_back(v);
            in_bit_stack.push_back(bit);
        } else {
            int incoming_bit = in_bit_stack.back();
            node_stack.pop_back();
            in_bit_stack.pop_back();
            if (incoming_bit != -1) {
                cycle_bits.push_back(incoming_bit);
            }
        }
    }

    reverse(cycle_bits.begin(), cycle_bits.end());

    string sequence(n - 1, '0');
    for (int bit : cycle_bits) {
        sequence.push_back(char('0' + bit));
    }
    return sequence;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << build_binary_de_bruijn(n) << '\n';
    return 0;
}
