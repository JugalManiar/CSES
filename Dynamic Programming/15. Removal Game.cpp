#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n, x[5001], dp[5001][5001], chck[5001][5001];
ll score(ll l, ll r){
    if(l==r) return dp[l][r]=x[l];
    else if(l+1==r) return dp[l][r]=max(x[l],x[r]);
    else if(chck[l][r]) return dp[l][r];
    chck[l][r]=1;
    return dp[l][r]=max( x[l]+min(score(l+1,r-1),score(l+2,r)) , min(score(l,r-2),score(l+1,r-1))+x[r] );
}
int main(){ NeedSpeed;
    cin>>n;
    FOR(i,0,n) cin>>x[i];
    cout<<score(0,n-1);
}