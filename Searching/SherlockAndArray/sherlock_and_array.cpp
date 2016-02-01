#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(const vector< int >& vec) {
    if (vec.size() == 1) {
        cout << "YES\n";
        return;
    }
    vector< int > sum(vec.size());
    sum[0] = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        sum[i] = sum[i - 1] + vec[i];
    }
    int cur = 0;
    bool flag = false;
    for (int i = vec.size() - 1; i >= 2; --i) {
        cur += vec[i];
        if (cur == sum[i - 2]) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector< int > vec(n);
        for (int j = 0; j < n; ++j) {
            cin >> vec[j];
        }
        solve(vec);
    }
    return 0;
}
