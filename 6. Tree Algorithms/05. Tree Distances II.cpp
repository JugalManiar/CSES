#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=200002;
vll v[N];
ll n, sum=0, d[N], sub[N], par[N], sod[N];
void dfs(ll x, ll p, ll y){
    d[x]=y++;
    sum+=d[x];
    par[x]=p;
    for(auto it:v[x]) if(it!=p) dfs(it,x,y);
}
ll subb(ll x){
    if(sub[x]) return sub[x];
    sub[x]=1;
    for(auto it:v[x]) if(it!=par[x]) sub[x]+=subb(it);
    return sub[x];
}
ll sumofdistances(ll x){
    if(sod[x]||x==1) return sod[x];
    return sod[x]=sumofdistances(par[x])+n-2*subb(x);
}
int main(){ NeedSpeed;
    ll a,b; cin>>n;
    while(cin>>a>>b){ v[a].pb(b); v[b].pb(a); }
    dfs(1,0,0); sod[1]=sum;
    FOR(i,1,n+1) sub[i]=subb(i);
    FOR(i,0,n) cout<<sumofdistances(i+1)<<" ";
}