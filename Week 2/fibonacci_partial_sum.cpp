#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int getAns(long long m, long long n){
    if (n <= 1){
        return n;
    }
    int prev = 0;
    int curr = 1;
    int sum;

    if(m <= 1){
        sum = 1;
    }
    else{
        sum = 0;
    }
    for (int i = 2; i <= n; i++){
        int temp = curr;
        curr = (curr + prev) % 10;
        prev = temp;

        if (i >= m){
            sum = (sum + curr) % 10;
        }
    }
    return sum;
}

int main()
{
    Fast;
    long long n,m;
    cin >> m >>n;
    m%=60;
    n%=60;
    if(n<m){
        n+=60;
    }
    long long ans = getAns(m,n);
    cout<<ans<<endl;
}
