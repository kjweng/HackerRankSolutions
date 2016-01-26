#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

long min_cost(const vector<int>& C, long N, long K) {
    long bought = 0;
    long cost = 0;
    while(bought < N) {
        cost += C[bought] * (bought / K + 1);
        ++bought;
    }
    return cost;
}

int main(void){
   int N, K;
   cin >> N >> K;
   vector<int> C(N);
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
    sort(C.begin(), C.end(), std::greater<int>());

   long result = min_cost(C, N, K);
   cout << result << "\n";
   
   return 0;
}
