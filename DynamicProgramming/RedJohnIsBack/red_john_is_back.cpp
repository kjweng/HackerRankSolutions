#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int number_of_primes(int n) {
    if (n < 2)
        return 0;
 
    vector<bool> primes(n + 1, true);
 
    for (int i = 2; i <= sqrt(n); ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
        }
    }
 
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (primes[i])
            ++count;
    }
 
    return count;
}

int arrange_bricks(int n) {
    vector<int> ways(n + 1, 1);
    for (int i = 4; i <= n; ++i) {
        ways[i] = ways[i - 1] + ways[i - 4];
    }
    return number_of_primes(ways[n]);
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << to_string(arrange_bricks(n)) << "\n";
    }
    return 0;
}