#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll n, ans=0, l=0, r=0;
    cin>>n; ll x[n]; omll m;
    while(cin>>x[r]){
        if(m[x[r]]) while(l<m[x[r]]) m[x[l++]]=0;
        m[x[r]]=r+1;
        ans+=1+(r++)-l;
    } cout<<ans;
}
