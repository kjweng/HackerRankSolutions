#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_children(vector< vector< int > >& adj, vector< int >& children, int v) {
    int total = 0;
    if (adj[v].size() && children[v] == 0) {
        for (int a : adj[v]) {
            total += count_children(adj, children, a);
        }
    }
    children[v] = total + 1;
    return children[v];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector< int > > adj(n, vector< int >());
    vector< int > children(n, 0);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        adj[v2].push_back(v1);
    }
    count_children(adj, children, 0);

    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (children[i] % 2 == 0)
            ++max;
    }
    cout << to_string(max);
    return 0;
}