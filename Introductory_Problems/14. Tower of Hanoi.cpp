#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
void print_steps(ll m, ll x, ll y){
    if(m==0) return;
    ll z=1^2^3^x^y; // z!=x, z!=y
    print_steps(m-1, x, z);
    cout<<x<<" "<<y<<"\n";
    print_steps(m-1, z, y);
}
ll ways(ll x){
    if(x==1) return 1;
    return (2*ways(x-1)+1);
}
int main(){ NeedSpeed;
    ll n; cin>>n;
    // Move the n−1 disks to the middle tower, move the largest disk to
    // the right tower, and then move the n−1 disks to the right tower.
    cout<<ways(n)<<"\n";
    print_steps(n,1,3);
}