#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define REVFOR(I,P,Q) for(ll I=P;I>=Q;I--)
const ll TT=1000000007LL;
ll binexp(ll A, ll B, ll M=TT){ A%=M; ll R=1; while(B>0){ if(B&1) R=(R*A)%M; A=(A*A)%M; B>>=1; } return R; }
ll modinv(ll A,ll M=TT){ return binexp(A,M-2,M); }
int main(){ NeedSpeed;
    ll n,ans;
    cin>>n;
    ll l=(n*(n+1)/2)+1,a[l];
    a[0]=1;
    FOR(i,1,l) a[i]=0;
    FOR(i,1,n+1) REVFOR(j,l-i-1,0) a[i+j]=(a[i+j]+a[j])%TT;
    ans=((n*(n+1)/2)%2)?0:((a[(n*(n+1)/4)]*modinv(2))%TT);
    cout<<ans;
}