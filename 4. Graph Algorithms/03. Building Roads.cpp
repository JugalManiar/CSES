#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
ll n,m,a,b;
vll v[100010];
ll vis[100010];
set<ll>j;
void check(ll x){
    vis[x]=1;
    for(auto it:v[x]) if(!vis[it]) check(it);
}
int main(){ NeedSpeed;
    cin>>n>>m;
    FOR(i,0,m){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } check(a);
    FOR(i,1,n+1) if(!vis[i]){
        j.insert(i);
        check(i);
    } cout<<j.size()<<"\n";
    for(auto it:j) cout<<a<<" "<<it<<"\n";
}
