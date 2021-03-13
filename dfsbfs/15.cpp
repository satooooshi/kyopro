// even-relation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n;
    cin>>n;
    vector<vector<pair<int,ll>>>g(n); // g[from].push_back({to, weight(from,to)});
    vector<ll>dist(n,-1);// -1 unvisited
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        if(w&1)w=1;
        else w=0;
        g[u-1].push_back({v-1,w}); // zero based index
        g[v-1].push_back({u-1,w});// undirected graph
    }

    stack<int>s;
    s.push(0);
    dist[0]=0;
    while(!s.empty()){
        int v=s.top();
        s.pop();
        for(auto nv:g[v]){
            if(dist[nv.first]!=-1)continue;// nv.fist==v
            dist[nv.first]=dist[v]+nv.second;// mark visited
            s.push(nv.first);
        }
    }

    for(int i=0;i<n;i++){
        cout<<(dist[i]%2==0?0:1)<<endl;
    }

    return 0;
}

