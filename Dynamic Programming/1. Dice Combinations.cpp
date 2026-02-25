#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n,dp[1000001], tt=1e9+7;
ll ans(ll n){
    if(dp[n]) return dp[n];
    else for(ll i=1;i<=6;i++) if(n>=i) dp[n]+=ans(n-i)%tt;
    return (dp[n]%tt);
}
int main(){ NeedSpeed;
    cin>>n; dp[0]=1;
    cout<<ans(n)<<endl;
}
