#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long nP2(long long n) {
    return n * (n - 1);
}

long long solve(const vector<long long>& arr) {
    unordered_map<long long, long long> num_cnt;
    for (int i = 0; i < arr.size(); ++i) {
        ++num_cnt[arr[i]];
    }
    long long pairs = 0;
    for(const auto& kv : num_cnt) {
        pairs += nP2(kv.second);
    }
    return pairs;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        cout << to_string(solve(arr)) << "\n";
    }
    return 0;
}