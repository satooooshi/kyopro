// D - Collision
// n nodes, n-1 edges -> acyclic
// 2部グラフ（同じ色同士,  二点間の偶奇）

#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int A, B; cin >> A >> B;
        G[A-1].push_back(B-1);
        G[B-1].push_back(A-1);
    }
    queue<int> que;
    vector<int> dis(N,-1);
    que.push(0);
    dis[0] = 0;
    while(!que.empty()){
        int t = que.front(); que.pop();
        for(int x: G[t]) if(dis[x] == -1) {
            dis[x] = dis[t] + 1;
            que.push(x);
        }
    }
    for(int i = 0; i < Q; i++){
        int A, B;cin >> A >> B;
        if(dis[A-1]%2 == dis[B-1]%2) cout << "Town" << endl;
        if(dis[A-1]%2 != dis[B-1]%2) cout << "Road" << endl;
    }
}