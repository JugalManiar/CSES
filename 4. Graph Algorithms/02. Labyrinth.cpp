#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define pb push_back
const ll N=1001, M=10000010;
ll n,m;
string s[N];
bool vis[N][N];
char par[N][N];
bool b=0;
vector<char> v;
void dfs(ll x, ll y, char c){
    if(!vis[x][y]){
    // cout<<x<<" "<<y<<" "<<c<<"\n";
        vis[x][y]=1;
        par[x][y]=c;
        if(s[x][y]=='B'){
            b=1; v.pb(c);
        }
        else if(!b&&s[x][y]!='#'){
            if(x+1<n&&!b) dfs(x+1,y,'D');
            if(x>1&&!b) dfs(x-1,y,'U');
            if(y+1<m&&!b) dfs(x,y+1,'R');
            if(y>1&&!b) dfs(x,y-1,'L');
            if(b){ v.pb(c); }
        }
    }
}
int main(){ NeedSpeed;
    ll x,y,xb,yb; cin>>n>>m;
    FOR(i,0,n){ cin>>s[i];
        FOR(j,0,m){ vis[i][j]=0;
            if(s[i][j]=='A'){ x=i, y=j; }
            if(s[i][j]=='B'){ xb=i, yb=j; }
        }
    } vis[n+1][m+1]=0;
    dfs(x,y,'a');
    if(v.size()){
        cout<<"YES\n"<<v.size()<<"\n";
        for(auto it:v) cout<<it;
    } else cout<<"NO\n";
    cout<<"\n"; if(par[xb][yb]){
        ll i=xb, j=yb; cout<<i<<" "<<j<<"\n";
        while(i!=x&&j!=y){
            char f=par[i][j];
            cout<<f;
            if(f=='U') j--;
            else if(f=='D') j++;
            else if(f=='R') i--;
            else if(f=='L') i++;
            else break;
        }
    }
}