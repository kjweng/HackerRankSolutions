#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Median {
    // min_heap stores values > median
    priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    // max_heap stores values <= median
    priority_queue<int, std::vector<int>, std::less<int> > max_heap;
public:
    double add(int n) {
        if (max_heap.empty()) {
            max_heap.push(n);
        } else if (max_heap.top() < n) {
            min_heap.push(n);
            while (max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        } else {
            max_heap.push(n);
            while ((max_heap.size() - min_heap.size()) > 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }        
        return get_median();
    }
    double get_median() {
        if (min_heap.size() == max_heap.size())
            return (min_heap.top() + max_heap.top()) / 2.0;
        else
            return max_heap.top();
    }
};

int main() {
    int n;
    cin >> n;
    Median median;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        cout.precision(1);
        cout << fixed << median.add(m) << "\n";
    }
    return 0;
}
