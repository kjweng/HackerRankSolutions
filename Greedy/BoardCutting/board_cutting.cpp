#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calc_cutting(const vector<long long>& hcosts, const vector<long long>& vcosts) {
    unsigned long long total = 0;
    int hcuts = 0;
    int vcuts = 0;
    
    while(vcuts < vcosts.size() && hcuts < hcosts.size()) {
        if (hcosts[hcuts] >= vcosts[vcuts]) {
            total += hcosts[hcuts] * (vcuts + 1) % 1000000007;
            ++hcuts;
        } else {
            total += vcosts[vcuts] * (hcuts + 1) % 1000000007;
            ++vcuts;
        }

    }
    while (vcuts < vcosts.size()) {
        total += vcosts[vcuts] * (hcuts + 1) % 1000000007;
        ++vcuts;
    }
    
    while (hcuts < hcosts.size()) {
        total += hcosts[hcuts] * (vcuts + 1) % 1000000007;
        ++hcuts;
    }

    return total % 1000000007;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int height, width;
        cin >> height >> width;
        vector<long long> height_cost(height - 1);
        vector<long long> width_cost(width - 1);
        for (int j = 0; j < height - 1; ++j) {
            cin >> height_cost[j];
        }
        for (int j = 0; j < width - 1; ++j) {
            cin >> width_cost[j];
        }
        sort(height_cost.begin(), height_cost.end(), greater<long long>());
        sort(width_cost.begin(), width_cost.end(), greater<long long>());
        cout << to_string(calc_cutting(height_cost, width_cost)) << "\n";
    }
    return 0;
}
