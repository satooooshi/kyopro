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

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;

Graph g;

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq; 
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}


int main() {

    int h,w;cin>>h>>w;
    vector<vector<int>>c(10,vector<int>(10));
    vector<vector<int>>a(h,vector<int>(w));
    g.resize(10); // 0-based
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>c[i][j];
            if(i!=j)g[i].push_back({j,c[i][j]});// if not pointing itself
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }

/*
    cout<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<c[i][j]<<" ";
        }cout<<endl;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
*/

    vector<int>from(10,inf);// from i to one
    for(int i=0;i<10;i++){
        vector<ll> dist(10, inf); // cost transforming from 1 to 0,2-9
        vector<int> prev(10, -1);
        dijkstra(g,i,dist,prev); // determine shortest path from i to one
        from[i]=(int)dist[1];
        //cout<<"i"<<i<<" to 1 needs "<<dist[1]<<endl;
    }
    int res=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]!=-1){
                res+=from[a[i][j]];
            }
        }
    }
    cout<<res<<endl;

    return 0;
}