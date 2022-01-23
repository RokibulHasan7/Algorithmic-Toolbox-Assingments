#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  vector<int>dp = {0};
  vector<int> op = {1};

  if(n == 1){
    sequence.push_back(1);
    return sequence;
  }

  for(int i = 2; i <= n;i++){
    int num1 = dp[i - 2], num2 = 1e9, num3 = 1e9;
    if(i % 2 == 0){
      num2 = dp[(i / 2) - 1];
    }
    if(i % 3 == 0){
      num3 = dp[(i / 3) - 1]; 
    }

    if(num1 >= num3 && num2 >= num3){
      op.push_back(3);
      dp.push_back(num3 + 1);
    }
    else if(num1 >= num2 && num3 >= num2){
      op.push_back(2);
      dp.push_back(num2 + 1);
    }
    else if(num2 >= num1 && num3 >= num1){
      op.push_back(1);
      dp.push_back(num1 + 1);
    }
  }

  int tmp = n;
  while(tmp >= 1){
    sequence.push_back(tmp);
    if(op[tmp - 1] == 1){
      tmp -= 1;
    }
    else if(op[tmp - 1] == 2){
      tmp /= 2;
    }
    else{
      tmp /= 3;
    }
  }
  
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
