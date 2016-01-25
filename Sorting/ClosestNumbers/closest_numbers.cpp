#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> diffs;
    sort(arr.begin(), arr.end());
    int min = (int)((unsigned int)-1 >> 1);    // max int
    for (int i = 0; i < n - 1; ++i) {
        int diff = arr[i + 1] - arr[i];
        if (diff < min) {
            min = diff;
            diffs.clear();
            diffs.push_back(arr[i]);
            diffs.push_back(arr[i + 1]);
        } else if (diff == min) {
            diffs.push_back(arr[i]);
            diffs.push_back(arr[i + 1]);
        }
    }
    
    for (int& diff : diffs) {
        cout << to_string(diff) << " ";
    }
    return 0;
}
