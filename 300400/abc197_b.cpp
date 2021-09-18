#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {
    int h,w,x,y;
    cin>>h>>w>>y>>x;// 0-indexed
    x--;
    y--;
    vector<string>g;
    for(int i=0;i<h;i++){
        string s;cin>>s;
        g.push_back(s);
    }

    // depth-first grid traverse
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {-1, 0, 1, 0};
    ll ans=1;
    for(int i=0;i<4;i++){
        int cx=x,cy=y;
        while(1){
            cx+=dx[i];
            cy+=dy[i];
            if(cx<0||cx>=w||cy<0||cy>=h)break;
            if(g[cy][cx]=='#')break;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
