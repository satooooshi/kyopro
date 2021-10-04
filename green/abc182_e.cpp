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
    vector<vector<int>>g(h,vector<int>(w,0)); // 0-based, akari 1, kabe 2
    vector<vector<int>>counted(h,vector<int>(w,0)); // 0-based, akari 1, kabe 2
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        a--;
        b--;
        g[a][b]=1;

    }
    for(int i=0;i<m;i++){
        int c,d;cin>>c>>d;
        c--;
        d--;
        g[c][d]=2;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }

    int cnt=0;
    for(int i=0;i<h;i++){
        int l=0;
        bool light=false;
        int j=0;
        for(;j<w;j++){
            if(g[i][j]==1){
                light=true;
            }
            if(g[i][j]==2&&light==true){
                cnt+=(j-l);
                light=false;
            }
            if(j-1>=0&&g[i][j-1]==2&&(g[i][j]==1||g[i][j]==0)){
                l=j;
            }
        }
        if(light){
            cnt+=(j-l);
        }
    }
    cout<<cnt<<endl;

    for(int j=0;j<w;j++){
        int t=0;
        bool light=false;
        int i=0;
        for(;i<h;i++){
            if(g[i][j]==1){
                light=true;
            }
            if(g[i][j]==2&&light==true){
                cnt+=(j-t);
                light=false;
            }
            if(j-1>=0&&g[i][j-1]==2&&(g[i][j]==1||g[i][j]==0)){
                t=j;
            }
        }
        if(light){
            cnt+=(i-t);
        }

        cout<<cnt<<endl;
    }

    

    return 0;
}
