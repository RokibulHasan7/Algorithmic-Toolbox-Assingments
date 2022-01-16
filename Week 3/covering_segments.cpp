#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

struct Segment
{
    int start, end;
};
bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
    return a.second < b.second;
}
vector<int> optimal_points(vector<Segment> &segments)
{
    int sz = segments.size();
    vector<pair<int,int>>vec;
    for(int i=0;i<sz;i++){
        vec.push_back({segments[i].start,segments[i].end});
    }
    sort(vec.begin(),vec.end(),compare);
    vector<int>Ans;
    for(int i=0;i<sz;i++){
        int tmp = vec[i].second;
        while(i+1<sz && tmp >= vec[i+1].first){
            i++;
        }
        Ans.push_back(tmp);
    }
    return Ans;
}

int main()
{
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << endl;
    for (size_t i = 0; i < points.size(); ++i)
    {
        cout << points[i] << " ";
    }
}
