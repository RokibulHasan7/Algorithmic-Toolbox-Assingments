#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>vec;
    for(int i=0;i<n;i++){
        long long tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.rbegin(),vec.rend());
    long long ans=vec[0]*vec[1];
    cout<<ans<<endl;
}
