#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lcs(const string& n, const string& m) {
    // This question is literally longest common subsequence with no backtracking
    vector< vector< int > > dp(n.size() + 1, vector<int>(m.size() + 1, 0));

    for (int i = 0; i < n.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            dp[i + 1][j + 1] = ((n[i] == m[j])) ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[n.size()][m.size()];
}


int main() {
    string n, m;
    cin >> n;
    cin >> m;

    cout << to_string(lcs(n, m));

    return 0;
}
