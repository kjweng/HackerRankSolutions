#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

vector<int> hash_string(const string& str) {
    vector<int> val(26, 0);
    for (char c : str) {
        ++val[c - 'a'];
    }
    return val;
}

int choose(int n, int k) {
    if (k > n) { return 0; } 
    if (k * 2 > n) { k = n - k;}
    if (k == 0) {return 1;}
    int result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int anagramic_pairs(const string& str) {
    map< vector<int> , int> hash;
    int count = 0;
    for (int i = 1; i < str.size(); ++i) {
        for (int j = 0; j <= str.size() - i; ++j) {
            vector<int> curr = hash_string(str.substr(j, i));
            ++hash[curr];
        }
        
        for (const auto& pair : hash) {
            if (pair.second > 1) {
                count += choose(pair.second, 2);
            }
        }
        
        hash.clear();
    }
    return count;
}

int main() {
    int T;
    vector<string> strs;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string in;
        cin >> in;
        strs.push_back(in);
    }
    for (string str: strs) {
        cout << anagramic_pairs(str) << "\n";    
    }
    return 0;
}