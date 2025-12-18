#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int main(){ NeedSpeed;
    ll x; cin>>x;
    ll ans=(x*(x+1))/2;
    while(cin>>x) ans-=x;
    cout<<ans;
}