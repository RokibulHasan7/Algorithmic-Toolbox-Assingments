#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int get_fibonacci_last_digit_naive(int n) {
    int fibo[n+10];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=n;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%10;
    }
    return fibo[n];
}

int main(){
    Fast;
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << endl;
}
