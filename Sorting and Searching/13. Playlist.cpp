#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll n, ans=1, l=0;
    cin>>n;
    ll k[n];
    omll m;
    FOR(r,0,n){
        cin>>k[r];
        if(m[k[r]]) while(l<m[k[r]]) m[k[l++]]=0;
        m[k[r]]=r+1;
        ans=max(ans,1+r-l);
    } cout<<ans;
}