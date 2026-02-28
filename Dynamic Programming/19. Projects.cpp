#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F first
#define S second
#define pb push_back
#define all(X) X.begin(),X.end()
#define ubvp(VP,P) upper_bound(VP.begin(),VP.end(),P)
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef pair<pair<ll,ll>,ll>ppll;
typedef vector<ppll>vppll;
const ll N=200001;
ll n,s,e,r,dp[N];
vppll vt;
void solve(){
    dp[0]=vt[0].S;
    FOR(i,1,n){
        ppll p={{vt[i].F.S,0},0};
        ll x=(--ubvp(vt,p))-vt.begin();
        dp[i]=max(dp[i-1],vt[i].S+(x>=0?dp[x]:0));
    } cout<<dp[n-1];
}
int main(){ NeedSpeed;
    cin>>n;
    while(cin>>s>>e>>r) vt.pb({{e,s},r}); 
    sort(all(vt)); solve();
}