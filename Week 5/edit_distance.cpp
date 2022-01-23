#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.size();
  int m = str2.size();
  int dp[n+5][m+5];
  int i = 0;
  while(i <= n){
    dp[i][0] = i;
    i++;
  }
  int j = 0;
  while(j <= m){
    dp[0][j] = j;
    j++;
  }
  for(int j = 1; j <= m; j++){
    for(int i = 1; i <= n; i++){
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }
      else{
        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
      }
    }
  }
  return dp[n][m];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
