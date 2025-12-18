#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    string s;
    cin>>s;
    ll last=0, count=1, ans=1, n=s.size();
    F(i,1,n){
        if(s[i]==s[last]) count++;
        else{ count=1; last=i; }
        ans=max(ans,count);
    } cout<<ans;
}