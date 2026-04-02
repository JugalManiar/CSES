#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,ans=0;
    cin>>n;
    ll a[n];
    F(i,0,n) cin>>a[i];
    ll max=a[0];
    F(i,1,n){
        if(a[i]>max) max=a[i];
        else ans+=max-a[i];
    } cout<<ans;
}
