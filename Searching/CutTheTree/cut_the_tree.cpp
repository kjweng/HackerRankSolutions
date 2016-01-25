#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int dfs(int node, vector< vector< int > >& nodes, vector< int >& values, vector< char >& visited) {
    int size = (int)nodes[node].size();
    int ret = 0;
    visited[node] = 1;
    for (int i = 0; i < size; ++i) {
        int next = nodes[node][i];
        if (!visited[next])
            ret += dfs(next, nodes, values, visited);
    }
    values[node] += ret;
    return values[node];
}

int main() {
    int N;
    cin >> N;
    vector< vector< int > > nodes(N + 1);
    vector< int > values(N + 1);
    vector< char > visited(N + 1, 0);
    int tot = 0;
    int best = std::numeric_limits< int >::max();

    for (int i = 1; i <= N; ++i) {
        cin >> values[i];
        tot += values[i];
    }
    for (int i = 0; i < (N - 1); ++i) {
        int a, b;        
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    dfs(1, nodes, values, visited);
    for (int i = 1; i <= N; ++i) {
        if (abs(tot - 2 * values[i]) < best){
            best = abs(tot - 2 * values[i]);
        }
    }
    cout << best;
    return 0;
}
