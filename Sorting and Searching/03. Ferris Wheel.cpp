#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define all(X) X.begin(),X.end()
typedef vector<ll> vll;
int main(){ NeedSpeed;
    ll n,x,ans=0,f=0; cin>>n>>x;
    vll v(n); FOR(i,0,n) cin>>v[i]; sort(all(v));
    FOR(i,0,n){
        ans++;
        if(v[n-1-i]+v[f]<=x) f++;
        if(n-1-i<=f) break;
    } cout<<ans;
}