#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define F first
#define S second
int main(){ NeedSpeed;
    ll n,m,ii=-1,jj=-1;
    cin>>n>>m;
    list<pair<ll,ll>>v;
    char c[n][m],ans[n][m]; 
    FOR(i,0,n) FOR(j,0,m){
        cin>>c[i][j];
        if(c[i][j]=='M') v.pb({i,j});
        else if(c[i][j]=='A'){ ii=i; jj=j; }
    } v.pb({ii,jj});
    ans[ii][jj]=' ';
    ii=-1; jj=-1;
    while(v.size()){
        ll i=(*v.begin()).F, j=(*v.begin()).S;
        if(c[i][j]=='A'&&(i==0||j==0||i==n-1||j==m-1)){
            ii=i; jj=j; break;
        } if(i&&c[i-1][j]=='.'){
            c[i-1][j]=c[i][j];  v.pb({i-1,j}); ans[i-1][j]='U';
        } if(j&&c[i][j-1]=='.'){
            c[i][j-1]=c[i][j];  v.pb({i,j-1}); ans[i][j-1]='L';
        } if(j+1<m&&c[i][j+1]=='.'){
            c[i][j+1]=c[i][j];  v.pb({i,j+1}); ans[i][j+1]='R';
        } if(i+1<n&&c[i+1][j]=='.'){
            c[i+1][j]=c[i][j];  v.pb({i+1,j}); ans[i+1][j]='D';
        } v.pop_front();
    } if(ii!=-1&&jj!=-1){
        string s="";
        while(ans[ii][jj]!=' '){
            s+=ans[ii][jj];
            if(ans[ii][jj]=='U') ii++;
            else if(ans[ii][jj]=='D') ii--;
            else if(ans[ii][jj]=='R') jj--;
            else if(ans[ii][jj]=='L') jj++;
            else break;
        } reverse(s.begin(),s.end());
        cout<<"YES\n"<<s.size()<<"\n"<<s<<"\n";
    } else cout<<"NO\n";
}