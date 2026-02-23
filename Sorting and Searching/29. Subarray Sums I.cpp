#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,x,l=0,curr=0,ans=0;
    cin>>n>>x; ll a[n];
    cin>>a[0]; curr=a[0];
    if(curr>x) curr-=a[l++];
    if(curr==x) ans++;
    FOR(r,1,n){
        cin>>a[r]; curr+=a[r];
        while(curr>x&&l<=r) curr-=a[l++];
        if(curr==x) ans++;
    } cout<<ans;
}