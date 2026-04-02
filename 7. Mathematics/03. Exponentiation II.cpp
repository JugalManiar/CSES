#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef vector<ll> vll;
ll exp(ll e, ll x, ll TT=1e9+7){
    ll r=1, y=1;
    while(y<=x){
        if(y&x) r=(r*e)%TT;
        e=(e*e)%TT; y<<=1;
    } return r;
}
ll bigexp(ll e, ll x, ll p, ll TT=1e9+7){
    return exp(e,exp(x,p,TT-1));
}
int main(){ NeedSpeed;
    ll t,a,b,c; cin>>t; while(t--){
        cin>>a>>b>>c; cout<<bigexp(a,b,c)<<"\n";
    }
} // Binary Exponentiation + Euler Totient Function