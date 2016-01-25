#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(const vector<int>& vec) {
    for (const int& n : vec)
        cout << to_string(n) << " ";
    cout << "\n";
}

int partition(vector<int>& vec, int lo, int hi) {
    int pivot = vec[hi];
    int j = lo;
    int i;
    for (i = lo; i < hi; ++i) {
        if (vec[i] <= pivot) {
            swap(vec[i], vec[j]);
            ++j;
        }
    }
    swap(vec[j], vec[hi]);
    return j;
}

void qsort_inplace(vector<int>& vec, int lo, int hi) {
    if (lo < hi) {
        int p = partition(vec, lo, hi);
        print(vec);
        qsort_inplace(vec, lo, p - 1);
        qsort_inplace(vec, p + 1, hi);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    qsort_inplace(vec, 0, n - 1);

    return 0;
}