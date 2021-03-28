// B - Minesweeper
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int h,w;
    cin>>h>>w;
    vector<string>v;
    int dy[8]={-1,0,1,0, -1,1,1,-1};
    int dx[8]={0,-1,0,1, -1,1,-1,1};
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(v[i][j]=='#')continue;
            int cnt=0;
            for(int k=0;k<8;k++){
                int ni=i+dy[k];
                int nj=j+dx[k];
                if(ni<0||ni>=h||nj<0||nj>=w)continue;
                if(v[ni][nj]=='#')cnt++;
            }
            v[i][j]='0'+cnt;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }

    return 0;
}
