#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
vll seq[19];
ll n;
void complete_seq(){
    FOR(k,1,19){
        for(ll i=0;i+1<seq[k-1].size();i+=2) seq[k].pb(0);
        if(seq[k].size()==1) break;
    }
}
void update(ll k1){
    ll o=0;
    while(1){
        if(k1<seq[o].size()) seq[o][k1]++;
        if(seq[o].size()==1) break;
        k1/=2; o++;
    }
}
ll sum(ll b){
    ll result=0,k=0;
    while(0<=b){
        if(!(b&1)) result+=seq[k][b--];
        b>>=1; k++;
    } return result;
}
ll original_index(ll x){ // Binary search for original index
    ll lo=x-1, hi=n-1,mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        if(mid+1>=x+sum(mid)) hi=mid;
        else lo=mid+1;
    } return hi;
}
int main(){ NeedSpeed;
    cin>>n; ll x[n],p;
    FOR(i,0,n){
        cin>>x[i];
        seq[0].pb(0);
    } complete_seq();
    FOR(i,0,n){ cin>>p;
        p=original_index(p);
        update(p);
        cout<<x[p]<<" ";
    }
}