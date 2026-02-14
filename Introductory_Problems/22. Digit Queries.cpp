#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll power(ll A, ll B){ ll R=1; while(B>0){ if(B&1) R*=A; A*=A; B>>=1; } return R; } // Binary Exponentiation 
int ans(ll x){
    ll t=9, i=1, s=0;
    while(x>(s+(t*i))){
        s+=t*(i++);
        t*=10; 
    } s=x-s-1;
    ll num=(s/i)+power(10,i-1), rem=i-(s%i); // num identifies the number, rem identifies the digit.
    if(rem) num/=power(10,rem-1);
    return (num%10);
}
int main(){ NeedSpeed;
    ll q,n; cin>>q;
    while(cin>>n) cout<<ans(n)<<"\n";
}