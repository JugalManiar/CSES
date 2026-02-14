#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll a,b,ans=0; omll m; cin>>a;
    while(cin>>a>>b){ m[a]++; m[b+1]--; }
    a=0; for(auto it:m){
        a+=it.second;
        ans=max(ans,a);
    } cout<<ans;
}