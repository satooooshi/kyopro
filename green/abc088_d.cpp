#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int H, W;
string B[50];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
int vis[55][55];
int dp[55][55];
int check() {
    queue<pair<int, int>> que;
    que.push({ 0, 0 });
    vis[0][0] = 1;
    while (!que.empty()) {
        auto q = que.front(); que.pop();
        int x, y;
        tie(x, y) = q;
 
        if (x == W - 1 and y == H - 1) return dp[y][x];
 
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx and xx < W and 0 <= yy and yy < H) {
                if (B[yy][xx] == '.' and vis[yy][xx] == 0) {
                    vis[yy][xx] = 1;
                    dp[yy][xx] = dp[y][x] + 1;
                    que.push({ xx, yy });
                }
            }
        }
    }
 
    return 0;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> H >> W;
    rep(y, 0, H) cin >> B[y];
 
    int ans, res = check();
    if (!res) ans = -1;
    else {
        ans = H * W - res - 1;
        rep(y, 0, H) rep(x, 0, W) if (B[y][x] == '#') ans--;
    }
 
    printf("%d\n", ans);
    return 0;
}


/* WHY WA???
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int h,w;
vector<vector<char>>s;
vector<vector<int>> dist;

void dfs(int i, int j) {
    for (int d = 0; d < 4; d++) {
        int ni = i + dy[d];
        int nj = j + dx[d];

        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (dist[ni][nj]!=-1) continue;
        dist[ni][nj]=dist[i][j]+1;
        dfs(ni, nj);
    }
}

int main() {
    cin>>h>>w;
    s.assign(h,vector<char>(w,'.'));
    dist.assign(h,vector<int>(w,-1));
    int wall=0;
    for (int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
            if(s[i][j]=='#')wall++;
        }
    } 
    
    dist[0][0]=0; // start point
    dfs(0, 0);

    if(dist[h-1][w-1]==-1){ // cannot reach s[h-1][w-1]
        cout<<-1<<endl;
        return 0;
    }

    //cout<<endl<<dist[h-1][w-1]<<endl;
    cout<<h*w-wall-dist[h-1][w-1]-1<<endl;// -1 start point



    return 0;
}
*/