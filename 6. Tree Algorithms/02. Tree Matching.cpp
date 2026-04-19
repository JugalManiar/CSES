#include <bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(I,P,Q) for(ll I=P;I<Q;I++)
#define pb push_back
#define max(A,B) (((A)>(B))?(A):(B))
const ll N=200001;
typedef vector<ll> vll;
vll v[N];
ll d[N][2];
ll ways(ll x, ll p, ll z){
    ll ans=0,ans1=1;
    if(d[x][z])
        return d[x][z];
    if(z){
        for(auto it:v[x])
            if(it!=p)
                ans1+=max(ways(it,x,0),ways(it,x,1));
        for(auto it:v[x])
            if(it!=p)
                ans=max(ans,ans1-max(ways(it,x,0),ways(it,x,1))+ways(it,x,0));
    } else
        for(auto it:v[x])
            if(it!=p)
                ans+=max(ways(it,x,0),ways(it,x,1));
    return d[x][z]=ans;
}
int main(){ NeedSpeed;
    ll n,a,b;
    cin>>n;
    FOR(i,1,n){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        d[i][0]=0;
        d[i][1]=0;
    } d[n][0]=0;
    d[n][1]=0;
    cout<<max(ways(1,0,0),ways(1,0,1));
}