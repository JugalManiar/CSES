#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
string strs[65537];
ll power(ll A, ll B){ // Binary Exponentiation.
    ll R=1; while(B>0){
        if(B&1) R*=A;
        A*=A;
        B>>=1;
    } return R;
}
void graycode(ll n){
    if(n>2) graycode(n-1);
    if(n>1){
        ll k=0;
        FOR(i, pow(2,n-1)+1, pow(2,n)+1) strs[i]=strs[((power(2,n-1))-k++)]+'1';
        FOR(i, 1, pow(2,n-1)+1) strs[i]+='0';
    }
}
int main(){ NeedSpeed;
    ll n; cin>>n;
    strs[1]="0"; strs[2]="1";
    graycode(n);
    FOR(i, 1, pow(2,n)+1) cout<<strs[i]<<"\n";
}