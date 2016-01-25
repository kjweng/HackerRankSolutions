#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(const vector<int>& vec, int k) {
    vector<int> max_weight(k + 1, 0);
    for (int w = 1; w <= k; ++w) {
        for (int e = 0; e < vec.size(); ++e) {
            int cur = vec[e];
            if (cur <= w) {
                max_weight[w] = max(max_weight[w - cur] + cur, max_weight[w]);
            }
        }
    }
    return max_weight[k];
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int j = 0; j < n; ++j) {
            cin >> vec[j];
        }
        cout << to_string(knapsack(vec, k)) << "\n";
    }
    return 0;
}