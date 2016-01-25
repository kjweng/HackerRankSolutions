#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int index(const string& str) {
    int i = 0;
    int j = str.size() - 1;
    int idx = -1;
    while (i < j) {
        if (str[i] != str[j]) {
            if (str[i + 1] == str[j]) {
                if (index(str.substr(0, i) + str.substr(i + 1)) == -1) {
                    idx = i;
                } else {
                    idx = j;
                }
            } else {
                if (index(str.substr(0, j) + str.substr(j + 1)) == -1) {
                    idx = j;
                } else {
                    idx = i;
                }
            }
            break;
        }
        ++i;
        --j;
    }
    return idx;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string str;
        cin >> str;
        cout << to_string(index(str)) << "\n";
    }
    return 0;
}