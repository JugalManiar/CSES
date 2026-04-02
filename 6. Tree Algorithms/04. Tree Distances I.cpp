#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=200001;
vll v[N];
ll x1=1, x2=1, d[N], d1[N];
void dfs(ll x, ll p, ll y, ll b){
    if(b<3) d[x]=y++;
    else if(b==3) d1[x]=y++;
    for(auto it:v[x]) if(it!=p) dfs(it,x,y,b);
    if(b==0 && d[x]>d[x1]) x1=x;
    if(b==1 && d[x]>d[x2]) x2=x;
}
int main(){ NeedSpeed;
    ll n,a,b; cin>>n; n++;
    while(cin>>a>>b){ v[a].pb(b); v[b].pb(a); }
    FOR(i,1,n) d[i]=0; dfs( 1,0,0,0);
    FOR(i,1,n) d[i]=0; dfs(x1,0,0,1);
    FOR(i,1,n) d[i]=0; dfs(x1,0,0,2);
    dfs(x2,0,0,3);
    FOR(i,1,n) cout<<max(d[i],d1[i])<<" ";
}