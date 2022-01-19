#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
  if(pos == a.size() || a[pos] != x){
    return -1;
  }
  return pos;
}

int main() {
  Fast;
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i]) << ' ';
  }
}
