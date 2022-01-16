#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int get_change(int m)
{
    int n = 0;
    while(m>0)
    {
        if(m>=10)
        {
            m-=10;
            n++;
        }
        else if(m>=5)
        {
            m-=5;
            n++;
        }
        else if(m>0)
        {
            m--;
            n++;
        }
    }
    return n;
}

int main()
{
    Fast;
    int m;
    cin >> m;
    cout << get_change(m) << endl;
}
