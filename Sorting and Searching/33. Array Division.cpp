#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n,k,a[200001];
bool chck(ll x){
    ll count=0, sm=0, y=0;
    FOR(i,0,n){
        if(a[i]>x) return 0;
        else if(a[i]+sm<x){
            count++; sm+=a[i];
        } else if(a[i]+sm==x){ 
            y++; count=0; sm=0;
        } else{
            y++; count=1; sm=a[i];
        }
    } if(count&&sm<=x) y++;
    if(y>k) return 0;
    else return 1;
}
int main(){ NeedSpeed;
    ll sum=0; cin>>n>>k; FOR(i,0,n){
        cin>>a[i]; sum+=a[i];
    } ll hi=sum, lo=sum/k, mid=(hi+lo)/2;
    while(lo<hi){
        chck(mid)?(hi=mid):(lo=mid+1);
        mid=(hi+lo)/2;
    } cout<<mid<<"\n";
}