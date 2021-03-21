// B - Problem Set

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<int,int>x;
    rep(i,n){
        int d;
        cin>>d;
        x[d]++;
    }
    int m;
    cin>>m;
    rep(i,m){
        int t;
        cin>>t;
        if(x[t]>0){
            x[t]--;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;


    return 0;
}
