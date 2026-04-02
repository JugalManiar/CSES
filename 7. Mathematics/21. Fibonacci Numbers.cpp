#include <bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,m=1e9+7;
    cin>>n; n--;
    if(n==-1){ cout<<0; return 0; }
    ll a=1,b=1,   p=1,q=0,
       c=1,d=0,   r=0,s=1;
    while(n>0){
        if(n&1){
            ll pp=(p*a+r*b)%m,
               qq=(a*q+b*s)%m,
               rr=(c*p+r*d)%m,
               ss=(c*q+d*s)%m;
            p=pp; q=qq;
            r=rr; s=ss;
        }
        ll aa=(a*a+c*b)%m,
           bb=(a*b+b*d)%m,
           cc=(c*a+c*d)%m,
           dd=(d*d+c*b)%m;
        a=aa; b=bb;
        c=cc; d=dd;
        n>>=1;
    } cout<<p;
} // Matrix Exponentiation
