#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intersect(pair<ll,ll> A,pair<ll,ll> B,pair<ll,ll> C)
{
    return (B.first - A.first)*(C.second - A.second) - (B.second - A.second)*(C.first - A.first);
}
vector< pair<ll,ll> > exactPoint(vector< pair<ll,ll> > pts)
{
    vector< pair<ll,ll> > hull;
    sort(pts.begin(), pts.end());
    for (ll i = 0; i < pts.size(); i++) {
        while (hull.size() >= 2 && intersect(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    ll s = hull.size();
    for (ll i = pts.size()-2; i >= 0; i--) {
        while (hull.size() >= s+1 && intersect(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    return hull;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n; vector< pair<ll,ll> >vp;
        vector<ll>v(n); multiset<ll>s;
        for(ll i=0;i<n;i++){
            cin>>v[i]; s.insert(v[i]);
        }
        for(ll i=0;i<n-1;i++){
            s.erase(s.find(v[i]));
            vp.push_back(make_pair(v[i],*(s.begin())));
            vp.push_back(make_pair(v[i],*(s.rbegin())));
        }
        vector< pair<ll,ll> >h=exactPoint(vp);
        ll area=0;
        for(ll i=0;i<h.size()-1;i++) 
			area += h[i].first*h[i+1].second - h[i+1].first*h[i].second;
        cout<<area<<endl;
    }
    return 0;
}
