#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void largest_permutation(vector<int>& arr, int k) {
    vector<int> index(arr.size() + 1, -1);
    int n = arr.size();
    for (int i = 0; i < arr.size(); ++i) {
        index[arr[i]] = i;
    }
    
    int j = arr.size();
    
    while(k > 0 && j > 0) {
        if (index[j] != (n - j)) {
            int temp_idx = index[j];
            int temp = arr[n - j];
            swap(arr[n - j], arr[index[j]]);
            index[temp] = temp_idx;
            index[j] = (n - j);
            --k;
        }
        --j;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    largest_permutation(arr, k);
    for (int a : arr) {
        cout << to_string(a) << " ";
    }
    
    return 0;
}