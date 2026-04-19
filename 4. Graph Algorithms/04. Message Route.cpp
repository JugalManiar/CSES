#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define F first
#define S second
typedef vector<ll> vll;
int main(){ NeedSpeed;
    ll n,m,a,b;
    cin>>n>>m;
    vll v[n+1];
    FOR(i,0,m){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } queue<pair<ll,ll>>q;
    q.push({1,0});
    ll par[n+1];
    FOR(i,0,n+1) par[i]=0;
    while(q.size()){
        pair<ll,ll>p=q.front();
        q.pop();
        for(auto it:v[p.F]) if(!par[it]&&it!=p.S){
            par[it]=p.F;
            q.push({it,p.F});
        }
    } if(par[n]){
        vll ans;
        ll o=n;
        while(o!=1){
            ans.pb(o);
            o=par[o];
        } ans.pb(1);
        cout<<ans.size()<<"\n";
        reverse(ans.begin(),ans.end());
        for(auto it:ans) cout<<it<<" ";
    } else cout<<"IMPOSSIBLE\n";
}