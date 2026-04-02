#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define F first
#define S second
#define all(X) X.begin(),X.end()
int main(){ NeedSpeed;
    string str, ans, tp; cin>>str;
    ll n=str.size(), count=0;
    unordered_map<char,ll> freq;
    FOR(i,0,n) freq[str[i]]+=1;
    for(auto it:freq) if(it.S&1){
        count++;
        tp=it.F;
    }
    if(count>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    for(auto it:freq) FOR(i,0,(it.S/2)) ans+=it.F;
    cout<<ans;
    if(count) cout<<tp;
    reverse(all(ans));
    cout<<ans;
}