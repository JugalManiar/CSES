#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
#define MOD(X) (((X)%TT+TT)%TT)
int main(){ NeedSpeed;
    ll n,x;
    cin>>n>>x;
    ll c[n],dp[x+1];
    FOR(i,0,n) cin>>c[i];
    sort(c,c+n);
    FOR(j,0,x+1) dp[j]=0;
    FOR(j,0,x+1) dp[j]=(j%c[0])?0:1;
    FOR(i,1,n) FOR(j,c[i],x+1) dp[j]=MOD(dp[j]+dp[j-c[i]]);
    cout<<dp[x];
}