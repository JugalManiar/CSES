#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int main(){ NeedSpeed;
    ll n, ans=0; cin>>n;
    while(n){
        ans+=n/5; n=n/5;
    } cout<<ans;
}