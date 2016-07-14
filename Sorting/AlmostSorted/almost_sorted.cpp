#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool verify(const vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void almostSorted(vector<int>& vec) {
    int upper, lower;
    upper = lower = -1;
    int i = 0;
    int len = vec.size();
    vec.push_back(2000000);
    
    while (i < len - 1) {
        if (vec[i] > vec[i + 1]) {
            lower = i;
            ++i;
            break;
        }
        ++i;
    }
    if (lower == -1) {
        cout << "yes\n";
    }
    
    // found a lower, check if we should reverse or swap
    if (vec[i] <= vec[i + 1]) {
        // swap
        while (i < len) {
            if (vec[i] > vec[i + 1]) {
                upper = i + 1;
                break;
            }
            ++i;
        }
        if (upper == -1) {
            upper = lower + 1;
        }
        iter_swap(vec.begin() + lower, vec.begin() + upper);
        if (verify(vec)) {
            cout << "yes\nswap " << lower + 1 << " " << upper + 1 << "\n";
        } else {
            cout << "no\n";
        }
    } else {
        // reverse
        while (i < len) {
            if (vec[i] < vec[i + 1]) {
                upper = i + 1;
                break;
            }
            ++i;
        }
        reverse(vec.begin() + lower, vec.begin() + upper);
        if (verify(vec)) {
            cout << "yes\nreverse " << lower + 1 << " " << upper << "\n";
        } else {
            cout << "no\n";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    vec.reserve(n + 1);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    almostSorted(vec);
    return 0;
}
