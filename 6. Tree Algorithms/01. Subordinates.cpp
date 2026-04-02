#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
typedef vector<ll> vll;
ll n,a,i=1,s[200001];
vll sub[200001];
ll subordinate(ll i){
    if(s[i]) return s[i];
    s[i]=1;
    for(auto it:sub[i]) s[i]+=subordinate(it);
    return s[i];
}
int main(){ NeedSpeed;
    cin>>n; s[0]=n;
    while(cin>>a) sub[a].pb(++i);
    FOR(i,1,n+1) cout<<(subordinate(i)-1)<<" ";
}