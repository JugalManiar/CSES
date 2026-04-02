#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n, ans=0;
    cin>>n; ll v[n];
    FOR(i,0,n) cin>>v[i];
    sort(v,v+n);
    FOR(i,0,n) ans+=abs(v[i]-v[n/2]);
    cout<<ans;
}