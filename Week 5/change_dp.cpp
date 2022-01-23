#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int get_change(int m) {
  int dp[m+1];
  int coin[4];
  coin[0] = 1; coin[1] = 3; coin[2] = 4;
  dp[0] = 0;
  for(int i = 1; i <= m; i++){
      dp[i] = 1e9;
      for(int j = 0; j < 3; j++){
          if(i >= coin[j]){
            dp[i] = min(dp[i], dp[i - coin[j]] + 1);
          }
      }
  }
  return dp[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << endl;
}
