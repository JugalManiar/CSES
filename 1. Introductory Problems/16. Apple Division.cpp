#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n, sum=0, batch=0, p[20];
void check(ll i, ll curr){
    if(i==n) return;
    check(i+1,curr);
    if(2*(curr+p[i])<=sum){
        curr+=p[i];
        check(i+1,curr);
        batch=max(batch,curr);
    }
}
int main(){ NeedSpeed;
    cin>>n;
    FOR(i,0,n){
        cin>>p[i];
        sum+=p[i];
    }
    check(0,0);
    cout<<sum-(2*batch);
}