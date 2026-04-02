#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
vll v[200001];
ll x1=1, x2=1, d[200001];
void dfs(ll x, ll p, ll y, bool b){
    d[x]=y++;
    for(auto it:v[x]) if(it!=p) dfs(it,x,y,b);
    if(b){ if(d[x]>d[x1]) x1=x; }
    else{  if(d[x]>d[x2]) x2=x; }
}
int main(){ NeedSpeed;
    ll n,a,b; cin>>n;
    while(cin>>a>>b){ v[a].pb(b); v[b].pb(a); }
    FOR(i,0,n) d[i+1]=0; dfs(1 ,0,0,1);
    FOR(i,0,n) d[i+1]=0; dfs(x1,0,0,0);
    cout<<d[x2];
}