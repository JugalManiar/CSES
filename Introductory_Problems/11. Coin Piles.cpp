#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int main(){ NeedSpeed;
    ll t; cin>>t; while(t--){
        ll p,q; cin>>p>>q; if(p<q){ p=p^q; q=p^q; p=p^q; }
        if(p>(2*q)) cout<<"NO\n";
        else cout<<(((p-(q/2)-2*(q%2))%3)?("NO\n"):("YES\n"));
    }
}