#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
const ll TT=1000000007LL;
ll n, dp_joint[1000001],dp_split[1000001];
int main(){ NeedSpeed;
    dp_joint[1]=1; dp_split[1]=1;
    FOR(x,2,1000001){
        dp_joint[x]=(dp_split[x-1]+2*dp_joint[x-1])%TT;
        dp_split[x]=(dp_joint[x-1]+4*dp_split[x-1])%TT;
    } cin>>n;
    while(cin>>n) cout<<(dp_joint[n]+dp_split[n])%TT<<"\n";
}