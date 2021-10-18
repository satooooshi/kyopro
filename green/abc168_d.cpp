#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    vector<bool> seen(V, false);  // 既に見たことがある頂点か記録する
    vector<int> previ(V, inf);
    queue<int> que;
    que.emplace(0);  // sから探索する
    seen[0] = true;
    previ[0]=-1;
    while (que.size() != 0) {     // 幅優先探索
        int state = que.front();  // 現在の状態
        que.pop();
        for (auto next : G[state]) {
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next] = true;
                previ[next]=state;
                que.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }

    for(int i=1;i<V;i++){
        if(seen[i]=false){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    for(int i=1;i<V;i++){
        cout<<previ[i]+1<<endl;
    }

    return 0;
}