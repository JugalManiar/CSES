#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll k,n,m; char c;
    cin>>n>>m; ll a[n][m];
    FOR(i,0,n) FOR(j,0,m){ cin>>c;
        if(c=='A') a[i][j]=1;
        else if(c=='B') a[i][j]=2;
        else if(c=='C') a[i][j]=4;
        else a[i][j]=8;
    } a[0][0]=(a[0][0]==1?2:1);
    FOR(i,1,n){
        k=15^(a[i-1][0]|a[i][0]);
        if(k&1) a[i][0]=1;
        else if(k&2) a[i][0]=2;
        else if(k&4) a[i][0]=4;
        else a[i][0]=8;
    } FOR(j,1,m){
        k=15^(a[0][j-1]|a[0][j]);
        if(k&1) a[0][j]=1;
        else if(k&2) a[0][j]=2;
        else if(k&4) a[0][j]=4;
        else a[0][j]=8;
    } FOR(i,1,n) FOR(j,1,m){
        k=15^(a[i][j]|a[i-1][j]|a[i][j-1]);
        if(k&1) a[i][j]=1;
        else if(k&2) a[i][j]=2;
        else if(k&4) a[i][j]=4;
        else a[i][j]=8;
    } FOR(i,0,n){
        FOR(j,0,m){
            if(a[i][j]==1) cout<<'A';
            else if(a[i][j]==2) cout<<'B';
            else if(a[i][j]==4) cout<<'C';
            else cout<<'D';
        } cout<<"\n";
    }
}