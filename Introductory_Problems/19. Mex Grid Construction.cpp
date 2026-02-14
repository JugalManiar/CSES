#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
typedef set<ll> sll;
int main(){ NeedSpeed;
    int n; cin>>n; ll a[n][n];
    sll row[n], col[n];
    FOR(i,0,n) FOR(j,i,n){
        ll x=0; sll temp;
        for(auto it:row[i]) temp.insert(it);
        for(auto it:col[j]) temp.insert(it);
        for(auto it:temp){
            if(it==x) x++;
            else break;
        } a[i][j]=x; a[j][i]=x;
        row[i].insert(x); col[j].insert(x);
        row[j].insert(x); col[i].insert(x);
    } FOR(i,0,n){ FOR(j,0,n) cout<<a[i][j]<<" "; cout<<"\n";}
}