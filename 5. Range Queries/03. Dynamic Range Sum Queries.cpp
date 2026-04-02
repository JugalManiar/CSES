#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
vll seq[19];
void complete_seq(){
    FOR(k,1,19){
        for(ll i=0;i+1<seq[k-1].size();i+=2) seq[k].pb(seq[k-1][i]+seq[k-1][i+1]);
        if(seq[k].size()==1) break;
    }
}
void update(ll k, ll u){
    ll o=0; u-=seq[0][k];
    while(1){
        if(k<seq[o].size()) seq[o][k]+=u;
        if(seq[o].size()==1) break;
        k/=2; o++;
    }
}
ll sum(ll a, ll b){
    ll result=0, k=0;
    while(a<=b){
        if(a&1) result+=seq[k][a++];
        if(!(b&1)) result+=seq[k][b--];
        a>>=1; b>>=1; k++;
    } return result;
}
int main(){ NeedSpeed;
    ll n,q,g,e,f; cin>>n>>q; ll x[n];
    FOR(i,0,n){
        cin>>x[i];
        seq[0].pb(x[i]);
    } complete_seq();
    while(q--){
        cin>>g>>e>>f;
        if(g==1) update(e-1,f);
        else cout<<sum(e-1,f-1)<<"\n";
    }
} // Segment Tree