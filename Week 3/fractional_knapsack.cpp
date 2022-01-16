#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    vector<pair<double,pair<int,int>>> vec;
    for(int i=0;i<values.size();i++){
        double tmp = (values[i]*1.0)/(1.0*weights[i]);
        vec.push_back({tmp,{values[i],weights[i]}});
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0;i<values.size() && capacity > 0;i++){
        value += (min(vec[i].second.second,capacity)*vec[i].first);
        capacity -= min(vec[i].second.second,capacity);
    }

    return value;
}

int main()
{
    Fast;
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
