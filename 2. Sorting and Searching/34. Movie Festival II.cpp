#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define all(X) X.begin(),X.end()
#define pb push_back
#define S second
#define F first
#define U_B upper_bound
#define B begin
typedef vector<pair<ll,ll>> vpll;
typedef multiset<ll> msll;
int main(){ NeedSpeed;
    ll n,k,ans=1; cin>>n>>k;
    vpll vp(n,{0,0}); msll ms;
    FOR(i,0,n) cin>>vp[i].S>>vp[i].F;
    sort(all(vp));  ms.insert(vp[0].F);
    FOR(i,1,n){
        if(ms.U_B(vp[i].S)==ms.B()){ if(ms.size()>=k) continue; }
        else ms.erase(--ms.U_B(vp[i].S));
        ms.insert(vp[i].F); ans++;
    } cout<<ans;
}