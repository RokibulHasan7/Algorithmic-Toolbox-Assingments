#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int>mp;
  int mx = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
    mp[a[i]]++;
    mx = max(mx, mp[a[i]]);
  }
  if(mx > n/2){
    cout<<1<<endl;
  }
  else{
    cout<<0<<endl;
  }
  
}
