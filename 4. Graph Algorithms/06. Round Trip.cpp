#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=100002;
ll ans=0,vis[N];
vll v[N];
void dfs(ll x, ll p){
    if(ans) return;
    vis[x]=p;
    for(auto it:v[x]) if(it!=p){
        if(vis[it]&&!ans){
            vis[it]=x;
            ans=x;
            break;
        } else dfs(it,x);
    }
}
int main(){ NeedSpeed;
    ll n,m,a,b;
    cin>>n>>m;
    FOR(i,0,m){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } FOR(i,0,n+1) vis[i]=0;
    FOR(i,1,n+1){
        if(ans) break;
        if(vis[i]==0) dfs(i,-1);
    } if(!ans) cout<<"IMPOSSIBLE";
    else{
        vll va;
        va.pb(ans);
        ll xx=vis[ans];
        while(xx!=ans){
            va.pb(xx);
            xx=vis[xx];
        } va.pb(ans);
        cout<<va.size()<<"\n";
        for(auto it:va) cout<<it<<" ";
    }
}
