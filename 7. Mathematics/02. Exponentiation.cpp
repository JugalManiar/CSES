#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
#define MOD(X) (((X)%TT+TT)%TT)
typedef vector<ll> vll;
ll exp(ll e, ll x){
    ll r=1, y=1;
    while(y<=x){
        if(y&x) r=MOD(r*e);
        e=MOD(e*e); y<<=1;
    } return r;
}
int main(){ NeedSpeed;
    ll t,a,b; cin>>t; while(t--){
        cin>>a>>b; cout<<exp(a,b)<<"\n";
    }
} // Binary Exponentiation