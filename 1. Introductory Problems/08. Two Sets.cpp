#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define printv(V) for(auto IT:V) cout<<IT<<' '; cout<<"\n"
int main(){ NeedSpeed;
    ll n; cin>>n;
    if((n*(n+1)/2)&1) cout<<"NO";
    else{ // Set1: Largest values + remaining target-sum value. 
        vector<ll>a,b;
        ll sum=n*(n+1)/4, last=n;
        while(last<sum){
            a.pb(last);
            sum-=last--;
        }
        if(sum) a.pb(sum);
        sort(a.begin(),a.end());
        F(i,1,n+1){
            if(sum!=i) b.pb(i);
            if(a.size()+b.size()==n) break;
        } cout<<"YES\n"<<a.size()<<"\n"; printv(a);
        cout<<     "\n"<<b.size()<<"\n"; printv(b);
    }
}
