#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll n,q,x1,x2,y1,y2; cin>>n>>q;
    ll t[n+1][n+1]; char c;
    FOR(i,1,n+1) FOR(j,1,n+1){ cin>>c;
        t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+(c=='*'?1:0);
    } while(q--){
        cin>>y1>>x1>>y2>>x2; y1--; x1--;
        cout<<(t[y2][x2]-t[y1][x2]-t[y2][x1]+t[y1][x1])<<"\n";
    }
}