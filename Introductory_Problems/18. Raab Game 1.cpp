#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define printv(V) for(auto IT:V) cout<<IT<<' '; cout<<"\n"
typedef vector<ll> vll;
int main(){ NeedSpeed;
    ll t,n,a,b; cin>>t; while(t--){
        cin>>n>>a>>b;
        if((a>0&&b==0)||(a==0&&b>0)||(a+b>n)) cout<<"NO\n";
        else{
            vll va, vb;
            FOR(i,0,n-a-b){
                va.pb(i+1);
                vb.pb(i+1);
            } FOR(i,0,min(a,b)){
                va.pb(n-a-b+i+1);
                vb.pb(n-i);
            } FOR(i,0,max(a,b)){
                va.pb(n-max(a,b)+i+1);
                vb.pb(n-a-b+i+1);
            } if(a<b) va.swap(vb);
            cout<<"YES\n"; printv(va); printv(vb);
        }
    }
}