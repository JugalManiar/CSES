#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef multiset<ll> msll;
int main(){ NeedSpeed;
    ll n,m,k,t; msll h;
    cin>>n>>m;
    FOR(i,0,n){ cin>>k;
        h.insert(k);
    } FOR(i,0,m){ cin>>t;
        auto it=h.upper_bound(t);
        if(it==h.begin()){
            cout<<"-1\n";
            continue;
        } cout<<*--it<<"\n";
        h.erase(it);
    }
}