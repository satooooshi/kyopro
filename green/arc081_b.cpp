#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<bool> seen;  // 既に見たことがある頂点か記録
vector<int> dist;
void dfs(const Graph &g, int v) {
    seen[v] = true;
    int cnt=3;
    for (int next=0;next<52;next++){
        if(g[v][next]==0)continue;
        if (seen[next])cnt--;// already colored
    }
    dist[v]=cnt;
    for (int next=0;next<52;next++){
        if(g[v][next]==0)continue;
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(g, next);
        }
    }
    //res.push_back(v); // pushes from leaf to the root
}

int main() {
    int n;cin>>n;
    vector<string>s(2);
    Graph g(52,vector<int>(52,0));// adjacent matrix

    map<char,int>m;
    for(int i=0;i<26;i++){
        m['A'+i]=i;
    }
    for(int i=0;i<26;i++){
        m['a'+i]=i+26;
    }
    //for(auto it=m.begin();it!=m.end();it++)cout<<it->first<<","<<it->second<<endl;


    for(int i=0;i<2;i++){
        cin>>s[i];
    }
    
        for(int j=0;j<n;j++){
            for(int i=0;i<2;i++){
            if( (j+1)<n && s[i][j]!=s[i][j+1] ){ // yoko
                //cout<<s[i][j]<<","<<s[i][j+1]<<endl;
                g[ m[s[i][j]] ][ m[s[i][j+1]] ]=1;
                //g[ m[s[i][j+1]] ][ m[s[i][j]] ]=1;
            }
            if( (i+1)<2 && s[i][j]!=s[i+1][j] ){
                //cout<<s[i][j]<<","<<s[i+1][j]<<endl;
                g[ m[s[i+1][j]] ][ m[s[i][j]] ]=1;
                //g[ m[s[i][j]] ][ m[s[i+1][j]] ]=1;
            }
        }
    }

    seen.assign(52, false);
    dist.assign(52, -1); 
    dfs(g,m[s[0][0]]);
    long long res=1;
    for(int i=0;i<52;i++){
        cout<<i<<","<<dist[i]<<endl;
        if(dist[i]!=-1){
            res*=dist[i];
            res%=1000000007;
        }
    }
    cout<<res<<endl;

    return 0;
}