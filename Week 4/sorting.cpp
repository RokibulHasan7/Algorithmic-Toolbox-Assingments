#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int partition(vector<int> &a, int l, int r) {
  int x = a[l];
  int i = l, j = r;
  while(i < j){
    do{
      i++;
    }while(a[i] <= x);

    do{
      j--;
    }while(a[j] > x);
    
    if(i < j){
      swap(a[i],a[j]);
    }
  }
    swap(a[l], a[j]);
    return j;

}

void quick_sort(vector<int> &a, int l, int r) {
  if(l < r){
    int tmp = partition(a, l, r);
    quick_sort(a, l, tmp);
    quick_sort(a, tmp + 1, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a[n] = 1e9+7;
  quick_sort(a, 0, n);
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
}
