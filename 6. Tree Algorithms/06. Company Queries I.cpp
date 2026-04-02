#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
const ll N=200002;
vll v[N];
ll n, d[N], bxk[N][20];
void dfs(ll x, ll p, ll y){
    d[x]=y;
    for(auto it:v[x]) if(it!=p) dfs(it,x,y+1);
}
ll xy(ll x, ll y){
    if(pow(2,y)>d[x]||x==-1||y<0) return -1;
    if(bxk[x][y]) return bxk[x][y];
    return bxk[x][y]=xy(xy(x,y-1),y-1);
}
ll kanc(ll x, ll k){
    ll o=1, c=0;
    while(o<=k){
        o<<=1; c++;
    } o>>=1; c--;
    while(o){
        if(o&k) x=xy(x,c);
        o>>=1; c--;
    } return x;
}
int main(){ NeedSpeed;
    ll a,b,q;
    cin>>n>>q;
    FOR(i,1,n){
        cin>>a;
        v[a].pb(i+1);
        bxk[i+1][0]=a;
    } dfs(1,0,0);
    while(cin>>a>>b) cout<<kanc(a,b)<<"\n";
}