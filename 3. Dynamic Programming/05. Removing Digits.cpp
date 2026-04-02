#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
ll dp[1000001];
ll ans(ll x){
    if(dp[x]) return dp[x];
    if(x<2) return x;
    ll k=1; dp[x]=x;
    while(k<=x){
        if((x/k)%10) dp[x]=min(dp[x],ans(x-((x/k)%10))+1);
        k*=10;
    } return dp[x];
}
int main(){ NeedSpeed;
    ll n; cin>>n; cout<<ans(n);
}