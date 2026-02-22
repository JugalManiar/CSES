#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n,t,k[200001];
bool chck(ll time){
    ll ans=0;
    FOR(i,0,n) ans+=time/k[i];
    if(ans>=t) return 1;
    return 0;
}
int main(){ NeedSpeed;
    cin>>n>>t;
    FOR(i,0,n) cin>>k[i];
    sort(k,k+n);
    ll lo=1,hi=k[0]*t,mid;
    while(lo<hi){
        mid=(hi+lo)/2;
        (chck(mid))?(hi=mid):(lo=mid+1);
    } cout<<lo<<"\n";
}