#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n;
    cin>>n;
    ll x[n];
    FOR(i,0,n) cin>>x[i];
    set<ll>s;
    s.insert(x[0]);
    s.insert(0);
    FOR(i,1,n) for(auto it=--s.end();;it--){
        s.insert(*it+x[i]);
        if(*it==0) break;
    } s.erase(s.begin()); 
    cout<<s.size()<<"\n";
    for(auto it:s) cout<<it<<" ";
}