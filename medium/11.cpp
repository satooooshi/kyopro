#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(n),c(m),d(m);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i]>>d[i];
    }

    for(int i=0;i<n;i++){
        ll md=4*(100000000)+1;
        int mj=-1;
        for(int j=0;j<m;j++){
            ll dist=abs(a[i]-c[j]);
            dist+=abs(b[i]-d[j]);
            if(md>dist){
                md=dist;
                mj=j;
            }
        }
        cout<<mj+1<<endl;
    }




    return 0;
}