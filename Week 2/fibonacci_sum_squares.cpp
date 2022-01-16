#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int getAns(long long n, int m){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        int num1 = 0;
        int num2 = 1;
        n = n % m;
        if(n ==0){
            return 0;
        }
        for(int i=2;i<=n; i++){
            int num3 = (num1+num2)%m;
            num1=num2;
            num2=num3;
        }
        return num2;
    }
}

int main() {
    Fast;
    long long n;
    cin >> n;
    int a = getAns(n, 60);
    int b = getAns(n+1, 60);
    int ans = (a*b)%10;
    cout<<ans<<endl;
}
