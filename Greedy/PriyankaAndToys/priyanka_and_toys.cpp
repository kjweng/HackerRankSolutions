#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector< int > arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int units = n;
    int cur = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] - cur <= 4) {
            --units;
        } else {
            cur = arr[i];
        }
    }
    cout << to_string(units);
    return 0;
}