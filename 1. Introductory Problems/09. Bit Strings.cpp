#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
const ll TT=1e9+7;
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
// Binary Exponentiation calculates (A^X)%T in O(log(X))
ll binexp(ll A, ll X, ll M=TT){
    ll Res=1; A%=M;
    while(X>0){
        if(X&1) Res=(Res*A)%M;
        A=(A*A)%M;
        X>>=1;
    } return Res;
}
int main(){ NeedSpeed;
    ll n; cin>>n;
    cout<<binexp(2,n);
}
