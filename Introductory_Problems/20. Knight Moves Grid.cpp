#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n, ans[1000][1000];
ll k=0;
ll steps(ll x, ll y){
    if(x==0 && y==0) return 0;
    if(x<0||y<0||x>=n||y>=n) return 1e9;
    if(ans[x][y]) return ans[x][y];
    return ans[x][y]=1+min(steps(x+1,y-2), min(steps(x-1,y-2), min(steps(x-2,y+1), steps(x-2,y-1))));
}
int main(){ NeedSpeed;
    cin>>n; ans[1][1]=4;
    ans[0][1]=3; ans[0][2]=2; ans[0][3]=n==4?5:3;
    ans[1][0]=3; ans[2][0]=2; ans[3][0]=n==4?5:3;
    FOR(i,0,n){
        FOR(j,0,n) cout<<steps(i,j)<<' ';
        cout<<"\n";
    }
}