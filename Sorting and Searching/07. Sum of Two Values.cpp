#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll n,x,t,b=1;
    omll m;
    cin>>n>>x;
    FOR(i,0,n){
        cin>>t;
        if(m[x-t]){
            cout<<m[x-t]<<" "<<i+1;
            b=0; break;
        } m[t]=i+1;
    } if(b) cout<<"IMPOSSIBLE";
}