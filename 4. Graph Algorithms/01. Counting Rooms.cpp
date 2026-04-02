#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
ll n,mm,rooms=0;
char a[1001][1001];
bool m[1001][1001];
void check(ll i, ll j){
    if(!m[i][j]){
        m[i][j]=1;
        if(a[i][j+1]==a[i][j]&&j+1<mm) check(i,j+1);
        if(a[i+1][j]==a[i][j]&&i+1<n) check(i+1,j);
        if(a[i-1][j]==a[i][j]&&i>0) check(i-1,j);
        if(a[i][j-1]==a[i][j]&&j>0) check(i,j-1);
    }
}
int main(){
    cin>>n>>mm;
    FOR(i,0,n) FOR(j,0,mm) cin>>a[i][j];
    check(0,0); if(a[0][0]=='.') rooms+=1;
    FOR(i,0,n) FOR(j,0,mm){
        if(m[i][j]) continue;
        if(a[i][j]=='.') rooms+=1;
        check(i,j);
    } cout<<rooms;
}
