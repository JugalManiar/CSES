#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,x; cin>>n>>x;
    ll c[n],dp[x+1]; dp[0]=0;
    FOR(i,0,n) cin>>c[i];
    FOR(i,1,x+1) dp[i]=1000001;
    FOR(i,1,x+1) FOR(j,0,n) if(i>=c[j]&&dp[i-c[j]]!=1000001) dp[i]=min(dp[i],dp[i-c[j]]+1);
    if(dp[x]==1000001) dp[x]=-1; 
    cout<<dp[x];
}