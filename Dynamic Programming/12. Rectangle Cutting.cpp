#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll dp[501][501];
ll ans(ll x, ll y){
    if(x==y) return dp[x][y]=0;
    else if(x==0||y==0) return dp[x][y]=10000;
    else if(dp[x][y]) return dp[x][y];
    else if(dp[y][x]) return dp[x][y]=dp[y][x];
    dp[x][y]=10000;
    FOR(i,1,x) dp[x][y]=min(dp[x][y],1+ans(x-i,y)+ans(i,y));
    FOR(i,1,y) dp[x][y]=min(dp[x][y],1+ans(x,y-i)+ans(x,i));
    return dp[x][y];
}
int main(){ NeedSpeed;
    ll x,y; cin>>x>>y; cout<<ans(x,y);
}