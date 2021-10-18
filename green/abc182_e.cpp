#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main(){

    int h,w,n,m;cin>>h>>w>>n>>m;
    vector<vector<int>>a(h,vector<int>(w,0)),b(h,vector<int>(w,0)); // 0-based, akari 1, kabe 2
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        x--;
        y--;
        a[x][y]=1;
    }
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;
        y--;
        a[x][y]=2;
    }
    for(int i=0;i<h;i++){
        int ok=0;
        for(int j=0;j<w;j++){
            if(a[i][j]==1)ok=1;
            if(a[i][j]==2)ok=0;
            b[i][j]|=ok;
        }
        ok=0;
        for(int j=w-1;j>=0;j--){
            if(a[i][j]==1)ok=1;
            if(a[i][j]==2)ok=0;
            b[i][j]|=ok;
        }
    }

    for(int i=0;i<w;i++){
        int ok=0;
        for(int j=0;j<h;j++){
            if(a[j][i]==1)ok=1;
            if(a[j][i]==2)ok=0;
            b[j][i]|=ok;
        }
        ok=0;
        for(int j=h-1;j>=0;j--){
            if(a[j][i]==1)ok=1;
            if(a[j][i]==2)ok=0;
            b[j][i]|=ok;
        }
    }
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(b[i][j])cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
