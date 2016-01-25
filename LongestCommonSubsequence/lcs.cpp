#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> backtrack(const vector< vector< int > >& dp, const vector<int>& seqN) {
    int n = dp.size();
    int m = dp[0].size();
    int len = dp[n][m];
    vector<int> seq(len, 0);
    
    int i = n - 1;
    int j = m - 1;
    
    while (i > 0 && j > 0) {
        if (dp[i][j] > dp[i][j - 1]) {
            if (dp[i - 1][j] == dp[i][j]) {
                --i;
            } else {
                seq[len - 1] = seqN[i - 1];
                --len;
                --j;
                --i;
            }
        } else {
            --j;
        }
    }
    return seq;
}

vector<int> lcs(const vector<int>& seqN, const vector<int>& seqM) {
    // Create n x m matrix, add 1 row and col of padding
    vector< vector< int > > dp(seqN.size() + 1, vector<int>(seqM.size() + 1, 0));

    for (int i = 0; i < seqN.size(); ++i) {
        for (int j = 0; j < seqM.size(); ++j) {
            dp[i + 1][j + 1] = ((seqN[i] == seqM[j])) ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return backtrack(dp, seqN);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> seqN(n);
    vector<int> seqM(m);
    for (int i = 0; i < n; ++i) {
        cin >> seqN[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> seqM[i];
    }
    
    vector<int> solution = lcs(seqN, seqM);
    for (int& item : solution) {
        cout << to_string(item) << " ";
    }
    return 0;
}
