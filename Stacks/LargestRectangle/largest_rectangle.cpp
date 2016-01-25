#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    stack<int> index_stk;
    int max = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    int index = 0;
    while (index < n) {
        if (index_stk.empty() || heights[index_stk.top()] < heights[index]) {
            index_stk.push(index);
            ++index;
        } else {
            int top = index_stk.top();
            index_stk.pop();
            int area = heights[top] * (index_stk.empty() ? index : index - index_stk.top() - 1);
            if (max < area) {
                max = area;
            }
        }
    }

    while(!index_stk.empty()) {
        int top = index_stk.top();
        index_stk.pop();
        int area = heights[top] * (index_stk.empty() ? index : index - index_stk.top() - 1);
        if (max < area) {
            max = area;
        }
    }
    cout << to_string(max);
    
    return 0;
}