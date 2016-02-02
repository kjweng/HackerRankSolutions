#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices(n);
    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    
    int answer = 0;
    
    sort(prices.begin(), prices.end());
    int total;
    total = 0;
    for (answer = 0; answer < n; ++answer) {
        total += prices[answer];
        if (total > k)
            break;
    }
    cout << answer << endl;
    
    return 0;
}