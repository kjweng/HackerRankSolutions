#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void algorithmL(string str) {
    int len = str.size();
    if (len < 2) {
        cout << "no answer\n";
    } else {
        int k, i;
        bool valid = false;
        for (k = len - 2; k >= 0; --k) {
            if (str[k] < str[k + 1]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "no answer\n";
        } else {
            for (i = len - 1; i >= 0; --i) {
                if (str[k] < str[i]) {
                    break;
                }
            }
            swap(str[k], str[i]);
            reverse(str.begin() + k + 1, str.end());
            cout << str << "\n";
        }
    }
}

int main() {
    int t;
    vector<string> strs;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string input;
        cin >> input;
        strs.push_back(input);
    }
    for (string str: strs) {
        algorithmL(str);
    }
    return 0;
}