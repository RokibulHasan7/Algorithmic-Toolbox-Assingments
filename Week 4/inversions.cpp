#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int merge(int arr[], int tmp[], int l, int mid, int r){
  int count = 0;
  int i = l, j = mid, k = l;
  
  while((i < mid) && (j < r)){
    if(arr[i] <= arr[j]){
      tmp[k] = arr[i];
      i++; k++;
    }
    else{
      tmp[k] = arr[j];
      j++; k++;
      count += (mid - i);
    }
  }

  while(i < mid){
    tmp[k] = arr[i];
    i++; k++;
  }

  while(j < r){
    tmp[k] = arr[j];
    j++; k++;
  }

  for(int p = l; p < r; p++){
    arr[p] = tmp[p];
  }
  return count;
}

int mergeSort(int arr[], int tmp[], int l, int r){
  int count = 0;
  if(l < r){
    int mid = (l + r)/2;
    count = mergeSort(arr, tmp, l, mid);
    count += mergeSort(arr, tmp, mid + 1, r);
    count += merge(arr, tmp, l, mid + 1, r);
  }
  return count;
}

int solve(int arr[], int sz){
  int tmp[sz];
  return mergeSort(arr, tmp, 0, sz);
}

int main() {
  Fast;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout<<solve(arr, n)<<endl;
}
