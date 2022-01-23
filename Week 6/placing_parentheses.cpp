#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  }
}

long long get_maximum_value(const string &exp) {
  int sz = exp.size();
  int operands = (sz + 1) / 2;
  ll mn[operands][operands] = {0};
  ll mx[operands][operands] = {0};

  for(int i = 0; i < operands; i++){
    mn[i][i] = stoll(exp.substr(2 * i, 1));
    mx[i][i] = stoll(exp.substr(2 * i, 1));
  }

  for(int i = 0; i < operands; i++){
    for(int j = 0; j < operands - i - 1; j++){
      int tmp = i + j + 1;
      ll MinVal = LLONG_MAX;
      ll MaxVal = LLONG_MIN;

      for(int k = j; k < tmp; k++){
        ll a = eval(mn[j][k], mn[k+1][tmp],exp[2 * k +1]);
        ll b = eval(mn[j][k], mx[k+1][tmp],exp[2 * k +1]);
        ll c = eval(mx[j][k], mn[k+1][tmp],exp[2 * k +1]);
        ll d = eval(mx[j][k], mx[k+1][tmp],exp[2 * k +1]);

        MinVal = min(MinVal, min(a, min(b, min(c, d))));
        MaxVal = max(MaxVal, max(a, max(b, max(c, d))));
      }

      mn[j][tmp] = MinVal;
      mx[j][tmp] = MaxVal;
    }
  }
  return mx[0][operands - 1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
