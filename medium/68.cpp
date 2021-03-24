// A - Shik and Stone
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int h,w;
    cin>>h>>w;
    vector<vector<char>>a(h);
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            if(c=='#')cnt++;
            a[i].push_back(c);

        }
    }

    if(cnt==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;


    return 0;
}


