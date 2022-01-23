#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int Zero_One_Knapsack(int W, const vector<int> &w) {
  int n = w.size();
  vector<vector<int>>  dp(n + 1,vector<int>(W + 1));
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= W; j++){
      if(i == 0 || j ==0){
        dp[i][j] = 0;
      }
      else if(w[i-1] <=  j){
        dp[i][j] = max(dp[i-1][j], w[i-1] + dp[i-1][j-w[i-1]]);
      }
      else{
        dp[i][j]= dp[i-1][j];
      }
    }
  }
  return dp[n][W];
}

int main() {
  Fast;
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << Zero_One_Knapsack(W, w) << '\n';
}

