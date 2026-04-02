#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int main(){ NeedSpeed;
    ll x, ans=INT_MIN, c=0;
    cin>>x;
    while(cin>>x){
        c+=x;
        ans=max(ans,c);
        if(c<0) c=0;
    } cout<<ans;
}