#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
int main(){ NeedSpeed;
    ll n; cin>>n;
    ll dp[n][n]; string s[n];
    FOR(i,0,n) cin>>s[i];
    dp[0][0]=(s[0][0]=='.')?1:0;
    FOR(i,1,n) dp[0][i]=(s[0][i]=='.')?dp[0][i-1]:0;
    FOR(i,1,n) dp[i][0]=(s[i][0]=='.')?dp[i-1][0]:0;
    FOR(i,1,n) FOR(j,1,n) dp[i][j]=(s[i][j]=='.')?((dp[i-1][j]+dp[i][j-1])%TT):0;
    cout<<dp[n-1][n-1];
}