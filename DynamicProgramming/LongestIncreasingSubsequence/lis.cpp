#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_ceil(const vector< int >& vec, int l, int r, int v) {
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (vec[m] >= v)
            r = m;
        else
            l = m;
    }
    return r;
}

int lis(const vector< int >& vec) {
    int N = vec.size();
    vector< int > tail_vec = { vec[0] };
    int len = 1;
    
    for (int i = 0; i < N; ++i) {
        if (vec[i] < tail_vec[0]) {
            tail_vec[0] = vec[i];
        } else if (vec[i] > tail_vec[len - 1]) {
            tail_vec.push_back(vec[i]);
            ++len;
        } else {
            tail_vec[get_ceil(tail_vec, -1, len - 1, vec[i])] = vec[i];
        }
    }
    return len;
}

int main() {
    int N;
    cin >> N;
    vector< int > vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    cout << to_string(lis(vec)); 

    return 0;
}