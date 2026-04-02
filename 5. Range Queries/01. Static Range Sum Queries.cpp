#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,q,a,b;
    cin>>n>>q;
    ll x[n],pre[n+1];
    pre[0]=0;
    FOR(i,0,n){
        cin>>x[i];
        pre[i+1]=pre[i]+x[i];
    } while(cin>>a>>b) cout<<pre[b]-pre[a-1]<<"\n";
} // Prefix Sum