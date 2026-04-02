#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef set<pair<ll,ll>> spll;
int main(){ NeedSpeed;
    ll a,i=0; spll sp; cin>>a;
    while(cin>>a){
        auto it=sp.lower_bound({a,0});
        if(it==sp.begin()) cout<<"0 ";
        else cout<<((--it)++)->second<<" ";
        for(auto itt=it;itt!=sp.end();) itt=sp.erase(itt);
        sp.insert({a,++i});
    }
}