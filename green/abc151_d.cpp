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


using P = pair<int, int>;
int H, W;
vector<vector<char>> maze;  // 迷路の内容を保存する配列
vector<vector<bool>> seen;  // 既に通った場所なのかを記録しておく配列
vector<vector<int>> dist;  // 既に通った場所なのかを記録しておく配列
P s, g;
int RES=-1;
// dfs with recursive
int dx[4] = {1, -1, 0, 0};  // dx,dy は次の探索場所への距離を表す（４方向分）
int dy[4] = {0, 0, 1, -1};
void dfs(P p) {
    for (int i = 0; i < 4; i++) {
        int ny = p.first + dy[i];                              // 次の探索場所の行番号
        int nx = p.second + dx[i];                             // 次の探索場所の列番号
        if (ny < 0 || H <= ny || nx < 0 || W <= nx) continue;  // 迷路の外に出るならスルー
        if (maze[ny][nx] == '#') continue;                     // 障害物があればスルー
        //if (seen[ny][nx]) continue;                            //探索済みならスルー
        if(dist[ny][nx]<=dist[p.first][p.second]+1)continue;
        //seen[p.first][p.second] = true;
        dist[ny][nx]=dist[p.first][p.second]+1;
        dfs(make_pair(ny, nx));
    }
}


int main() {
    cin >> H >> W;
    maze.assign(H, vector<char>(W, '.'));// 0-based
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(maze[i][j]=='#')continue;
            //seen.assign(H, vector<bool>(W, false));
            dist.assign(H, vector<int>(W, inf));
            dist[i][j]=0;
            dfs(make_pair(i, j));

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if(maze[i][j]!='#')chmax(RES,dist[i][j]);
                }    
            }  
            //seen.clear();
            dist.clear();
        }
    }
    cout<<RES<<endl;

    return 0;
}