#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(vector<long long>& arr, long long N, long long K) {
    sort(arr.begin(), arr.end());
    vector<long long> sums(N, 0);
    sums[0] = arr[0];
    for(long long i = 1; i < N; ++i) {
        sums[i] = sums[i - 1] + arr[i];
    }
    long long c = 1 - K;
    long long minimum, current, prev;
    prev = 0;
    for (long long i = 0; i < K; ++i) {
        prev += c * arr[i];
        c += 2;
    }
    minimum = prev;
    current = 0;
    for (long long i = K; i < N; ++i) {
        current = prev + (K - 1) * (arr[i] + arr[i - K]) - 2 * (sums[i - 1] - sums[i - K]);
        minimum = min(current, minimum);
        prev = current;
    }
    cout << to_string(minimum);
}
int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> arr(N, 0);
    for(long long i = 0; i < N; i++) {
        cin >> arr[i];
    }
    solve(arr, N, K);
    return 0;
}