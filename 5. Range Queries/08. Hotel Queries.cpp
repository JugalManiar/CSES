#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
vll seq[19];
ll maxk=0;
void complete_seq(){
    FOR(k,1,19){ maxk=max(maxk,k);
        for(ll i=0;i+1<seq[k-1].size();i+=2) seq[k].pb(max(seq[k-1][i],seq[k-1][i+1]));
        if(seq[k].size()==1) break;
    }
}
void update(ll k, ll u){
    ll o=1; seq[0][k]=u; k/=2;
    while(1){
        if(o>maxk) break;
        if(k<seq[o].size()) seq[o][k]=max(seq[o-1][2*k],seq[o-1][1+2*k]);
        if(seq[o].size()==1) break;
        k/=2; o++;
    }
}
ll min_ind(ll r){
    if(seq[maxk][0]<r) return 0;
    ll k=maxk, c=0;
    while(k>0){ k--;
        if(seq[k][2*c]>=r) c=2*c;
        else c=1+2*c;
    } return (c+1);
}
int main(){ NeedSpeed;
    ll n,m,r,f=1; cin>>n>>m;
    ll h[n]; while(f<n) f<<=1;
    FOR(i,0,n){ cin>>h[i];
        seq[0].pb(h[i]);
    } FOR(i,n,f) seq[0].pb(0);
    if(n>1) complete_seq();
    while(m--){
        cin>>r;
        ll i=min_ind(r); cout<<i<<" ";
        if(i) update(i-1,seq[0][i-1]-r);
    } // Segment Tree to reach minimum index with value > group size.
}