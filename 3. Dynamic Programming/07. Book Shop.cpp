#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,x;
    cin>>n>>x;
    ll h[n],s[n],dp[x+1];
    FOR(i,0,x+1) dp[i]=0;
    FOR(i,0,n) cin>>h[i];
    FOR(i,0,n) cin>>s[i];
    FOR(i,0,n) FOR(j,0,x-h[i]+1) dp[x-j]=max(dp[x-j],dp[x-j-h[i]]+s[i]);
    cout<<*max_element(dp,dp+x+1);
}