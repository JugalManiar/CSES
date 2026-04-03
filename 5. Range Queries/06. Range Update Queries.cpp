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
        for(ll i=0;i+1<seq[k-1].size();i+=2) seq[k].pb(0);
        if(seq[k].size()==1) break;
    }
}
void update(ll k1, ll k2, ll u){
    ll o=0;
    while(1){
        if(k1<seq[o].size()) seq[o][k1]+=u;
        if(k2<seq[o].size()) seq[o][k2]-=u;
        if(seq[o].size()==1) break;
        k1/=2; k2/=2; o++;
    }
}
ll sum(ll b){
    ll result=0,k=0;
    while(0<=b){
        if(!(b&1)) result+=seq[k][b--];
        b>>=1; k++;
    } return result;
}
int main(){ NeedSpeed;
    ll n,q,a,b,u;
    cin>>n>>q;
    ll x[n];
    FOR(i,0,n){
        cin>>x[i];
        seq[0].pb(0);
    } complete_seq();
    while(q--){
        cin>>u;
        if(u==1){
            cin>>a>>b>>u; a--;
            update(a,b,u);
        }
        else{ cin>>u;
            cout<<x[u-1]+sum(u-1)<<"\n";
        }
    } // Segment Tree but on difference array. 
}