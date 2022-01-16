#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.push_back(dist);
    int sz = stops.size();
    int Ans = 0;
    int pos = 0;
    for(int i = 0; i<sz ;i++){
        if(stops[i]-pos>tank){
            return -1;
        }
        while(i+1<sz && stops[i+1]-pos<=tank){
            i++;
        }
        pos=stops[i];
        Ans++;
        //cout<<i<<" "<<Ans<<endl;
    }
    return Ans-1;
}


int main() {
    Fast;
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << endl;

    return 0;
}
