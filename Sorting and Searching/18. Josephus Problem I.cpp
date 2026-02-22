#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define p_f pop_front
typedef deque<ll> dqll;
int main(){ NeedSpeed;
    ll n,t=0; cin>>n; dqll dq;
    FOR(i,0,n) dq.pb(i+1);
    while(dq.size()){
        if(t) cout<<dq[0]<<" ";
        else dq.pb(dq[0]);
        t^=1; dq.p_f();
    }
}