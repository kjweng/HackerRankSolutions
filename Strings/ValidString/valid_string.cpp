#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string input;
    cin >> input;
    
    vector<int> freq(26, 0);
    
    for (char& c : input) {
        ++freq[c - 'a'];
    }
    int freq1 = 0;
    int freq1_count = 0;
    int freq2 = 0;
    int freq2_count = 0;
    int possible = true;
    // in order for there to only require max 1 removal, only 2 distinct frequencies can exist
    for (int& f : freq) {
        if (f > 0) {
            if (!freq1) {
                freq1 = f;
                ++freq1_count;
            } else if (!freq2 && f != freq1) {
                freq2 = f;
                ++freq2_count;
            } else {
                if (f == freq1) {
                    ++freq1_count;
                } else {
                    ++freq2_count;
                }
                if (min(freq1_count, freq2_count) > 1)  {
                    possible = false;
                    break;
                }
                if (f != freq1 && f != freq2) {
                    possible = false;
                    break;
                }
            }
        }
    }
    
    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}