#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define FOR(X,Y,Z) for(ll X=Y;X<Z;X++)
#define all(X) X.begin(),X.end()
int main(){ NeedSpeed;
    bool k, diag1[15], diag2[15], board[8][8];
    string s="01234567";
    ll ans=0, col;
    char c;
    FOR(row,0,8) FOR(col,0,8){
        cin>>c;
        board[row][col]=(c=='*'?1:0);
    } while(next_permutation(all(s))){
        k=1;
        memset(diag1,0,15);
        memset(diag2,0,15);
        FOR(row,0,8){
            col=(s[row]-'0');
            if(board[row][col] || diag1[7+row-col] || diag2[row+col]){
                k=0;
                break;
            } diag2[row+col]=1;
            diag1[7+row-col]=1;
        } ans+=k;
    } cout<<ans;
}