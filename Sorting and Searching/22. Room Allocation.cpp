#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define F first
#define S second
int main(){ NeedSpeed;
    ll n,a,b; cin>>n;
    ll ans[n];
    set<pair<ll,ll>>sp;
    vector<pair<pair<ll,ll>,ll>>v;
    FOR(i,0,n){
        cin>>a>>b;
        v.push_back({{b,a},i});
    } sort(v.begin(),v.end());
    ans[v[0].S]=1;
    sp.insert({v[0].F.F,1});
    FOR(i,1,n){
        auto it=sp.lower_bound({v[i].F.S,0});
        if(it==sp.begin()) ans[v[i].S]=sp.size()+1;
        else{
            ans[v[i].S]=(--it)->S;
            sp.erase(it);
        } sp.insert({v[i].F.F,ans[v[i].S]});
    } cout<<sp.size()<<"\n";
    FOR(i,0,n) cout<<ans[i]<<" ";
}