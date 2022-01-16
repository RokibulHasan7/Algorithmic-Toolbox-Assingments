#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    Fast;
    long long n,m;
    cin >> n >> m;
    long long GCD = __gcd(n,m);
    long long LCM = (n*m)/GCD;
    cout<<LCM<<endl;
}
