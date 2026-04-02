#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=200002;
vll v[N],seq[19];
ll n, q, val[N], ind[N], ind_end[N];
void dfs(ll x, ll p){
    ind    [x]=seq[0].size(); seq[0].pb( val[x]);
    for(auto it:v[x]) if(it!=p) dfs(it,x);
    ind_end[x]=seq[0].size(); seq[0].pb(-val[x]);
}
void complete_seq(){
    FOR(k,1,19){
        for(ll i=0;i+1<seq[k-1].size();i+=2) seq[k].pb(seq[k-1][i]+seq[k-1][i+1]);
        if(seq[k].size()==1) break;
    }
}
void update(ll s, ll x){
    ll i=ind[s], j=ind_end[s], k=0; x=x-seq[0][i];
    while(1){
        if(i<seq[k].size()) seq[k][i]+=x;
        if(j<seq[k].size()) seq[k][j]-=x;
        if(seq[k].size()==1) break;
        i/=2; k++; j/=2;
    }
}
ll sum(ll l, ll r){
    ll result=0, k=0;
    while(l<=r){
        if(l&1) result+=seq[k][l++];
        if(!(r&1)) result+=seq[k][r--];
        l>>=1; r>>=1; k++;
    } return result;
}
int main(){ NeedSpeed;
    ll a,b,s,x; cin>>n>>q;
    FOR(i,0,n) cin>>val[i+1];
    FOR(i,1,n){ cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    } dfs(1,0); complete_seq();
    while(q--){ cin>>b>>s;
        if(b==1){ cin>>x; update(s,x);
        } else cout<<sum(0,ind[s])<<"\n";
    }
}