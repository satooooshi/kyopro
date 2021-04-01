// B - fLIP
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    int n,m,k;
    cin>>n>>m>>k;

    bool ok=false;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*(m-j)+j*(n-i)==k){
                ok=true;
                break;
            }
        }
    }

    cout<<(ok?"Yes":"No")<<endl;

    return 0;
}


