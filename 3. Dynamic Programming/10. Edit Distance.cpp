#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.size(),m=s2.size(),dp[n][m];
    FOR(i,0,n) FOR(j,0,m){
        if(i==0&&j==0)dp[i][j]=((s1[i]==s2[j])?0:1);
        else if(i==0) dp[i][j]=((s1[i]==s2[j])?j:j+1);
        else if(j==0) dp[i][j]=((s1[i]==s2[j])?i:i+1);
        else dp[i][j]=(s1[i]==s2[j]?dp[i-1][j-1]:(1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})));
    } cout<<dp[n-1][m-1];
}