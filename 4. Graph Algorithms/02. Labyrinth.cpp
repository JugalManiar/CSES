#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
#define F first
#define S second
const ll N=1001, M=10000010;
char a[N][N];
list<pair<ll,ll>>lst;
pair<ll,ll>p[N][N];
ll level[N][N];
int main(){ NeedSpeed;
    ll n,m,sx,sy,ex,ey,x,y;
    cin>>n>>m;
    FOR(i,0,n) FOR(j,0,m){
        cin>>a[i][j];
        level[i][j]=M;
        if(a[i][j]=='A'){
            sx=i;
            sy=j;
        } else if(a[i][j]=='B'){
            ex=i;
            ey=j;
        }
    } lst.pb({sx,sy});
    level[sx][sy]=0;
    while(lst.size()&&level[ex][ey]==M){
        x=(*lst.begin()).F; y=(*lst.begin()).S;
        if((a[x+1][y]=='B'||a[x+1][y]=='.')&&level[x+1][y]>level[x][y]+1&&x+1<n){
            level[x+1][y]=level[x][y]+1;
            p[x+1][y]={x,y}; lst.pb({x+1,y});
        } if((a[x][y+1]=='B'||a[x][y+1]=='.')&&level[x][y+1]>level[x][y]+1&&y+1<m){
            level[x][y+1]=level[x][y]+1;
            p[x][y+1]={x,y}; lst.pb({x,y+1});
        } if((a[x-1][y]=='B'||a[x-1][y]=='.')&&level[x-1][y]>level[x][y]+1&&x>0){
            level[x-1][y]=level[x][y]+1;
            p[x-1][y]={x,y}; lst.pb({x-1,y});
        } if((a[x][y-1]=='B'||a[x][y-1]=='.')&&level[x][y-1]>level[x][y]+1&&y>0){
            level[x][y-1]=level[x][y]+1;
            p[x][y-1]={x,y}; lst.pb({x,y-1});
        } lst.pop_front();
    } if(level[ex][ey]<M){
        vector<char>s; x=ex; y=ey; char f;
        FOR(i,0,level[ex][ey]){
            if(p[x][y].F==x-1&&p[x][y].S==y)
                f='D';
            else if(p[x][y].F==x+1&&p[x][y].S==y)
                f='U';
            else if(p[x][y].F==x&&p[x][y].S==y-1)
                f='R';
            else if(p[x][y].F==x&&p[x][y].S==y+1)
                f='L';
            s.pb(f);
            ll xx=x;
            x=p[x][y].F;
            y=p[xx][y].S;
        } cout<<"YES\n"<<level[ex][ey]<<"\n";
        FOR(i,0,level[ex][ey])
            cout<<s[level[ex][ey]-1-i];
        cout<<"\n";
    } else cout<<"NO\n";
}
