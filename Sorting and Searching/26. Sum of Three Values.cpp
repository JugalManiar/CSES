#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F first
#define S second
typedef set<pair<ll,ll>> spll;
int main(){ NeedSpeed;
    ll n,x,v,i=0;
    cin>>n>>x;
    spll s;
    while(cin>>v) s.insert({v,i+++1});
    for(auto i=s.begin();i!=s.end();i++){
        if(i->F>x) break;
        for(auto j=i;j!=s.end();j++){
            if(i->F+j->F>x) break;
            auto k=s.lower_bound({x-i->F-j->F,0});
            if(k==s.end()||i==j) continue;
            else if(j==k||i==k){
                k++;
                if((j==k||i==k)&&k!=s.end()) k++;
                if(k==s.end()) continue;
            } if(x==i->F+j->F+k->F){
                cout<<i->S<<" "<<j->S<<" "<<k->S;
                return 0;
            }
        }
    } cout<<"IMPOSSIBLE";
}