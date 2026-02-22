#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int main(){ NeedSpeed;
    ll t, sum=0, mx=0;
    cin>>t; while(cin>>t){
        sum+=t;
        mx=max(mx,t);
    } cout<<max(sum,2*mx);
}