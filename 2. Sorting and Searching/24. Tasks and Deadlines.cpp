#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,d,ans=0,i=0; cin>>n; ll a[n];
    while(cin>>a[i++]>>d) ans+=d;
    sort(a,a+n);
    FOR(i,0,n) ans-=(a[i]*(n-i));
    cout<<ans;
}