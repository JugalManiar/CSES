#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,q,a,b;
    cin>>n>>q;
    ll seq[20][n];
    FOR(i,0,n) cin>>seq[0][i];
    FOR(k,1,20){
        FOR(i,0,n){
            ll j=pow(2,k-1);
            if(i+j<n) seq[k][i]=min(seq[k-1][i],seq[k-1][i+j]);
            else seq[k][i]=seq[k-1][i];
        }
    }
    while(cin>>a>>b){
        ll ans=INT_MAX; a--;
        while(a<b){
            ll i=1, k=0;
            while(a+i<=b){
                i*=2; k++;
            } i/=2; k--;
            ans=min(ans,seq[k][a]); a+=i;
        } cout<<ans<<"\n";
    };
} // Sparse Table (Can also done with segment tree, but since static, it would be an overkill)