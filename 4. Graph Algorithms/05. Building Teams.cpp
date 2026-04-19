#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll>vll;
ll n,m,a,b,r=1;
vll v[100010];
ll u[100010], team[100010];
void check(ll x, ll p){
    if(u[x]==1){ if(p==team[x]) r=0; }
    else{
        if(team[x]==1||team[x]==2){
            if(p==team[x]) r=0;
            else{
                u[x]=1;
                for(auto it:v[x]) check(it,team[x]);
            }
        } else{
            team[x]=p^1^2;
            u[x]=1;
            for(auto it:v[x]) check(it,team[x]);
        }
    }
}
int main(){ NeedSpeed;
    cin>>n>>m;
    team[1]=1;
    FOR(i,0,m){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } for(ll i=1;i<=n&&r;i++){
        if(team[i]==1||team[i]==2) check(i,team[i]^1^2);
        else check(i,1);
        u[i]=1;
    } if(r) FOR(i,1,n+1) cout<<team[i]<<" ";
    else cout<<"IMPOSSIBLE";
}