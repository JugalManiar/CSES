#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll x,a,curr=0,ans=0;
    cin>>a>>x;
    omll m; m[0]=1;
    while(cin>>a){
        curr+=a;
        ans+=m[curr-x];
        m[curr]++;
    } cout<<ans;
}