#include<bits/stdc++.h>
using namespace std;
#define NeedSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define F(X,Y,Z) for(ll X=Y;X<Z;X++)
int main(){ NeedSpeed;
    ll tc,x,y; cin>>tc; while(tc--){
        cin>>x>>y; // 4 directions -> 4 Cases.
        cout<<(
            x>y?
                x&1?
                    (x-1)*(x-1)+y   // 1.
                    : (x*x)+1-y     // 2.
            :   y&1?
                    (y*y)+1-x       // 3.
                    : (y-1)*(y-1)+x // 4.
        )<<"\n";
    }
}