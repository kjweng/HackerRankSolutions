#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];

    std::sort(list, list + N);
    
    for (int i = 0; i < (N - K + 1); ++i) {
        unfairness = std::min(unfairness, list[i + K - 1] - list[i]);
    }
    cout << unfairness << "\n";
    return 0;
}