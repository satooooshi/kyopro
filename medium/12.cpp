// B - Grid Compression
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
    vector<bool>sc(w,false),sr(h,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            a[i].push_back(c);
        }
    }

    rep(i,h){
       if(count(a[i].begin(),a[i].end(),'.')==w){
           sr[i]=true;
       }
    }

    rep(j,w){
        bool skip=true;
        rep(i,h){
            if(a[i][j]!='.'){
                skip=false;
            }
        }
        if(skip)sc[j]=true;
    }

    rep(i,h){
        if(sr[i])continue;
        rep(j,w){
            if(sc[j])continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
    






    return 0;
}

