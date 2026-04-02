#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n, ans=1;
    cin>>n; ll x[n];
    FOR(i,0,n) cin>>x[i];
    sort(x,x+n); FOR(i,0,n){
        if(ans<x[i]) break;
        ans+=x[i];
    } cout<<ans;
}