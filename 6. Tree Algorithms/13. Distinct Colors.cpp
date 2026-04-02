#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=200002;
ll n,a,b,c[N],r[N];
set<ll>s[N];
vll v[N];
void dfs(ll x, ll p){
    s[x].insert(c[x-1]);
    for(auto it:v[x]) if(it!=p){
        dfs(it,x);
        if(s[x].size()<s[it].size()) s[x].swap(s[it]);
        for(auto y:s[it]) s[x].insert(y);
    } r[x]=s[x].size();
}
int main(){ NeedSpeed;
    cin>>n;
    FOR(i,0,n) cin>>c[i];
    FOR(i,1,n){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } dfs(1,0);
    FOR(i,0,n) cout<<r[i+1]<<" ";
}