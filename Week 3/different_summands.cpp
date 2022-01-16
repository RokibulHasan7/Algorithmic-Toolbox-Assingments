#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

vector<int> optimal_summands(int n)
{
    vector<int> summands;
    for(int i=1;;i++){
        if(n-i > i){
            summands.push_back(i);
            n-=i;
        }
        else{
            summands.push_back(n);
            break;
        }
    }
    return summands;
}

int main()
{
    int n;
    cin >> n;
    vector<int> summands = optimal_summands(n);
    cout << summands.size() << endl;
    for (size_t i = 0; i < summands.size(); ++i)
    {
        cout << summands[i] << ' ';
    }
}
