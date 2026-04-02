#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define all(X) X.begin(),X.end()
typedef vector<ll> vll;
int main(){ NeedSpeed;
    ll n,m,k,ans=0,i=0,j=0;
    cin>>n>>m>>k; vll a(n),b(m);
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,m) cin>>b[i];
    sort(all(a)); sort(all(b));
    while(i<n&&j<m){
        if(b[j]<a[i]-k) j++;
        else if(b[j]>a[i]+k) i++;
        else{ ans++; i++; j++; }
    } cout<<ans;
}