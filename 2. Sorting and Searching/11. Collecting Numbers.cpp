#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define all(X) X.begin(),X.end()
#define pb push_back
#define S second
typedef vector<pair<ll,ll>> vpll;
int main(){ NeedSpeed;
    ll n,x,ans=1;
    vpll vp; cin>>n;
    FOR(i,0,n){ cin>>x;
        vp.pb({x,i});
    } sort(all(vp));
    FOR(i,1,n) if(vp[i].S<vp[i-1].S) ans++;
    cout<<ans;
}