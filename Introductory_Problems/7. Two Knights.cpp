#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n; cin>>n;
    F(i,1,n+1) // Sequence & Series. 
        cout<<((i*i*(i*i-1)/2)-((i-2)*(i-1)*4))<<"\n";
}