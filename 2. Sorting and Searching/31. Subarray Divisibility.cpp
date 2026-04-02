#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
typedef map<ll,ll> omll;
int main(){ NeedSpeed;
    ll n,a,curr=0,ans=0;
    omll m; m[0]=1;
    cin>>n; while(cin>>a){
        curr=((curr+a)%n+n)%n;
        ans+=m[curr];
        m[curr]++;
    } cout<<ans;
}