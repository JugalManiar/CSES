#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef map<ll,ll> omll;
const ll TT=1e9+7;
#define MOD(X) (((X)%TT+TT)%TT)
int main(){ NeedSpeed;
    ll n, ans=1, x; cin>>n;
    omll m; while(cin>>x) m[x]++;
    for(auto it:m) ans=MOD(ans*(1+it.second));
    cout<<--ans;
}
