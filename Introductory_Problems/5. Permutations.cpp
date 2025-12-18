#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F2(X,Y,Z) for(ll X=Y;X<=Z;X+=2)
int main(){ NeedSpeed;
    ll n; cin>>n;
    if(n==2||n==3) cout<<"NO SOLUTION";
    else{
        F2(i,2,n) cout<<i<<" "; // 2 4 6 8...
        F2(i,1,n) cout<<i<<" "; // 1 3 5 7...
    }
}