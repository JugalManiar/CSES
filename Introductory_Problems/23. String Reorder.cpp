#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define F first
#define S second
#define all(X) X.begin(),X.end()
typedef map<char,ll> omcll;
int main(){ NeedSpeed;
    string s, ans=" ";
    cin>>s; ll n=s.size();
    sort(all(s));
    omcll m; FOR(i,0,n) m[s[i]]++;
    FOR(i,0,n){
        auto mx=m.begin();
        for(auto it=m.begin();it!=m.end();it++) if(it->S>mx->S) mx=it;
        if(mx->S<=((n-i)/2)){
            mx=m.begin();
            while(mx->F==ans[ans.size()-1]) mx++;
        } else if(mx->F==ans[ans.size()-1]) break;
        if(mx==m.end()) break;
        ans+=mx->F; m[mx->F]-=1;
        if(!m[mx->F]) m.erase(mx);
    } ans.erase(0,1);
    if(ans.size()!=n) ans="-1";
    cout<<ans;
}