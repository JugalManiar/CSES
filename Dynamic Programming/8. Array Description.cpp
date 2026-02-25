#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
int main(){ NeedSpeed;
    ll n,m,c=0; cin>>n>>m; ll x[n]; FOR(i,0,n) cin>>x[i];
    ll dp[n][m+1];
    FOR(i,0,n) FOR(j,0,m+1) dp[i][j]=0;
    if(x[0]) dp[0][x[0]]=1;
    else FOR(i,1,m+1) dp[0][i]=1;
    FOR(i,1,n){
        if(x[i]){
            if(x[i]>1&&x[i]<m) dp[i][x[i]]=(dp[i-1][x[i]-1]+dp[i-1][x[i]]+dp[i-1][x[i]+1])%TT;
            else if(x[i]>1) dp[i][x[i]]=(dp[i-1][x[i]-1]+dp[i-1][x[i]])%TT;
            else if(x[i]<m) dp[i][x[i]]=(dp[i-1][x[i]]+dp[i-1][x[i]+1])%TT;
        } else{
            dp[i][1]=(dp[i-1][1]+dp[i-1][2])%TT;
            FOR(j,2,m) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%TT;
            if(m>1) dp[i][m]=(dp[i-1][m-1]+dp[i-1][m])%TT;
        }
    } FOR(i,1,m+1) c=(c+dp[n-1][i])%TT;
    cout<<(x[n-1]?dp[n-1][x[n-1]]:c);
}