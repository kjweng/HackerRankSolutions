#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool has_substring(const string& A, const string& B) {
    unordered_set<char> char_set;
    for (const char& c : A) {
        char_set.insert(c);
    }
    for (const char& d : B) {
        auto iter = char_set.find(d);
        if (iter != char_set.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string A, B;
        cin >> A >> B;
        bool has = has_substring(A, B);
        if (has) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
