// C - Streamline
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,m;
    while(cin>>n>>m){
        vector<int>a(m);
        rep(i,m){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<int>b(m-1);
        for(int i=1;i<m;i++){
            b[i-1]=abs(a[i]-a[i-1]);
            //cout<<"b"<<b[i-1]<<endl;
        }
        if(n>=m){
            cout<<0<<endl;
            return 0;
        }
        if(n==1&&m==2){
            cout<<abs(a[1]-a[0])<<endl;
            return 0;
        }

        sort(b.begin(),b.end(),greater<int>());
        cout<<accumulate(b.begin()+n-1,b.end(),0)<<endl;

    }


    return 0;
}
