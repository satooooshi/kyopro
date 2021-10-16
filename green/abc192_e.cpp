// https://algo-logic.info/dijkstra/
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    long long to;
    long long cost;
    long long dept_time;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
Graph g;

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
    g.assign(n);
    vector<ll> dist(10, INF);
    vector<int> prev(10, -1);
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
        for (auto e : G[v]) {
                long long arrive_time=-1;
                if(dis[v]<e.dept_time){
                    if(dis[v]==0)arrive_time=e.cost;// @ start node ,set out @ 0
                    else arrive_time=e.dept_time+e.cost; 
                }else{
                    if(dis[v]%e.dept_time==0){
                        arrive_time=dis[v]+e.cost;
                    }else{
                        arrive_time=(dis[v]/e.dept_time+1)*e.dept_time+e.cost;
                    }
                }
                if(dis[e.to] > arrive_time){
                    dis[e.to] = arrive_time;
                    //dis[e.to] = dis[v] + e.cost;
                    prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                    pq.emplace(dis[e.to], e.to);
                }
        }
    }
}

vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main(){
    int n,m,x,y;cin>>n>>m>>x>>y;
    x--;
    y--;
    g.resize(n);
    for(int i=0;i<m;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;//0-based
        b--;
        g[a].push_back({b,c,d});
        g[b].push_back({a,c,d});
    }

    vector<long long>dist;
    vector<int>prev;
    dijkstra(g,x,dist,prev);
    if(dist[y]!=INF){
        cout<<dist[y]<<endl;
    }else{
        cout<<-1<<endl;
    }
    //for(auto e:get_path(prev,y))cout<<e<<" "<<dist[e]<<endl;;
    
    //for(int i=0;i<n;i++){cout<<k<<" to "<<i<<" = "<<dist[i]<<endl;}

    return 0;
}