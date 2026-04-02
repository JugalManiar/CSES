#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll x[200010], u[200010];
int main(){ NeedSpeed;
    ll n,m,p,q,c=1;
    cin>>n>>m;
    FOR(i,0,n){
        cin>>x[i];
        u[x[i]]=i;
    } FOR(i,1,n) if(u[i+1]<u[i]) c++;
    while(m--){
        cin>>p>>q;
        if(--p==--q){
            cout<<c<<"\n";
            continue;
        } if(x[p]>x[q]) swap(p,q);
        if(u[x[p]]<u[x[p]-1]&&x[p]>1) c--;
        if(u[x[p]+1]<u[x[p]]&&x[p]<n) c--;
        if(x[q]!=x[p]+1&&u[x[q]]<u[x[q]-1]&&x[q]>1) c--;
        if(u[x[q]+1]<u[x[q]]&&x[q]<n) c--;
        swap(x[p],x[q]);
        u[x[p]]=p;
        u[x[q]]=q;
        swap(p,q);
        if(u[x[p]]<u[x[p]-1]&&x[p]>1) c++;
        if(u[x[p]+1]<u[x[p]]&&x[p]<n) c++;
        if(x[q]!=x[p]+1&&u[x[q]]<u[x[q]-1] && x[q]>1 ) c++;
        if(u[x[q]+1]<u[x[q]]&&x[q]<n) c++;
        cout<<c<<"\n";
    }
}