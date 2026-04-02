#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define max(A,B) (((A)>(B))?(A):(B))
typedef vector<ll> vll;
const ll N=200002;
vll v[N];
ll n, d[N], bxk[N][20];
void dfs(ll x, ll p, ll y){
    bxk[x][0]=p; d[x]=y;
    for(auto it:v[x]) if(it!=p) dfs(it,x,y+1);
}
ll kanc(ll x, ll k){
    if(x==-1) return -1;
    ll o=1, c=0;
    while(o<=k){
        o<<=1; c++;
    } o>>=1; c--;
    while(o){
        if(o&k) x=bxk[x][c];
        o>>=1; c--;
    } return x;
}
ll lca(ll x, ll y){
    if(d[x]>d[y]) x=kanc(x,d[x]-d[y]);
    else if(d[x]<d[y]) y=kanc(y,d[y]-d[x]);
    if(x==y) return x;
    ll k=17; 
    while(x!=y&&k>=0){
        if(bxk[x][k]!=bxk[y][k]){ x=bxk[x][k]; y=bxk[y][k]; }
        k--;
    } return bxk[x][0];
}
int main(){ NeedSpeed;
    ll a,b,q; cin>>n>>q;
    FOR(k,0,18){ bxk[1][k]=-1; bxk[0][k]=-1; }
    FOR(i,1,n){ cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    } dfs(1,0,0);
    FOR(k,1,18) FOR(i,2,n+1){
        if(bxk[i][k-1]!=-1) bxk[i][k]=bxk[bxk[i][k-1]][k-1];
        else bxk[i][k]=-1;
    } while(cin>>a>>b) cout<<(d[a]+d[b]-2*d[max(1,lca(a,b))])<<"\n";
}