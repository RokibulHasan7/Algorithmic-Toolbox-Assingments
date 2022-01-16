#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
bool compare(string &s1, string &s2){
    return (s2+s1 < s1+s2);
}
string largest_number(vector<string> a)
{
    sort(a.begin(),a.end(),compare);
    string Ans="";
    for(int i=0;i<a.size();i++){
        Ans+=a[i];
    }
    return Ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    cout << largest_number(a);
}
