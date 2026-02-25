#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
int main(){ NeedSpeed;
    ll n,x;
    cin>>n>>x;
    ll c[n], dp[x+1];
    FOR(i,0,n) cin>>c[i];
    sort(c,c+n);
    dp[0]=1;
    FOR(j,1,x+1) dp[j]=0;
    FOR(j,1,x+1) FOR(i,0,n){
        if(c[i]>j) break;
        dp[j]=(dp[j]+dp[j-c[i]])%TT;
    } cout<<dp[x];
}