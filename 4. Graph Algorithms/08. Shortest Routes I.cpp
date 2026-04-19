#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define F first
#define S second
typedef vector<pair<ll,ll>> vpll;
int main(){ NeedSpeed;
    ll n,m;
    cin>>n>>m;
    ll a,b,c;
    vpll v[n+1];
    FOR(i,0,m){
        cin>>a>>b>>c;
        v[a].pb({c,b});
    } FOR(i,0,n)
        sort(v[i].begin(),v[i].end());
    set<pair<ll,ll>>s;
    ll len[n+1];
    len[1]=0;
    FOR(i,2,n+1)
        len[i]=1e15;
    bool vis[n+1];
    vis[1]=1;
    FOR(i,2,n+1) vis[i]=0;
    for(auto it:v[1])
        s.insert({it.F,it.S});
    while(s.size()){
        auto it=s.begin();
        b=it->S; c=it->F;
        len[b]=min(len[b],c);
        s.erase(it);
        if(!vis[b]){
            vis[b]=1;
            for(auto itt:v[b])
                s.insert({itt.F+len[b],itt.S});
        }
    } FOR(i,1,n+1) cout<<len[i]<<" ";
}