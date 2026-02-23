#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll n,k,ans=0,l=0,i=-1;
    cin>>n>>k; omll m; ll a[n];
    while(cin>>a[++i]){
        m[a[i]]++;
        while(m.size()>k&&l!=i) if(--m[a[l++]]==0) m.erase(a[(--l)++]);
        if(m.size()<=k) ans+=i-l+1;
    } cout<<ans;
}