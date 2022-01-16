#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long get_fibonacci_last_digit_naive(long long n, long long m) {
    int fibo[n+10];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=n;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%m;
    }
    return fibo[n];
}
int getPisano(long long m){
    int res = 0;
    int prev = 0;
    int curr = 1;
    for(int i=0;i<m*m;i++){
        int tmp = curr;
        curr = (prev+curr)%m;
        prev = tmp;
        if(curr==1 && prev==0){
            res = i + 1;
        }
    }
    return res;
}
int main() {
    Fast;
    long long n, m;
    cin >> n >> m;
    long long periodLen = getPisano(m);
    //cout<<periodLen<<endl;
    long long newN;
    newN = n % periodLen;
    cout << get_fibonacci_last_digit_naive(newN, m) << endl;
}
