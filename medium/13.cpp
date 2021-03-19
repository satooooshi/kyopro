// C - Traveling
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>t(n),x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>t[i]>>x[i]>>y[i];
    }

    for(int i=1;i<n;i++){
        int d=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        int dt=t[i]-t[i-1];

        if(d>dt){
            cout<<"No"<<endl;
            return 0;
        }
        if((d&1)!=(dt&1)){
            cout<<"No"<<endl;
            return 0;
        }
    }

    if(n==1&&t[0]>1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;


    return 0;
}
