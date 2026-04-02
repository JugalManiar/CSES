#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef set<ll> sll;
typedef multiset<ll> msll;
int main(){ NeedSpeed;
    ll x,n; cin>>x>>n;
    sll s; s.insert(0); s.insert(x);
    msll f; f.insert(x);
    while(cin>>x){
        auto it=s.lower_bound(x), itt=it--;
        f.erase(f.find(*itt-*it));
        f.insert(x-*it);
        f.insert(*itt-x);
        s.insert(x);
        cout<<*f.rbegin()<<" ";
    }
}