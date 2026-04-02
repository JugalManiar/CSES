#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define printv(V) for(auto IT:V) cout<<IT<<'\n';
#define all(X) X.begin(),X.end()
int main(){ NeedSpeed;
    string s; vector<string> ans;
    cin>>s; sort(all(s));
    ans.pb(s);
    while(next_permutation(all(s))) ans.pb(s);
    // next_permutation gives next lexicographically greater permutation.
    cout<<ans.size()<<"\n"; printv(ans);
}