#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[(i + k) % n];
    }
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        cout << to_string(arr[query]) << "\n";
    }
    return 0;
}