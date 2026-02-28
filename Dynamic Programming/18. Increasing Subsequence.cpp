#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll a; set<ll>s;
    cin>>a; while(cin>>a){
        auto it=s.lower_bound(a);
        if(it!=s.end()) s.erase(it);
        s.insert(a);
    } cout<<s.size();
}