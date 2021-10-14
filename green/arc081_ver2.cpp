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


// WA!!
int main() {
    int n;cin>>n;
    vector<string>s(2);
    for(int i=0;i<2;i++)cin>>s[i];

    int prev=-1;
    long long ans=1;
    for(int j=0;j<n;){
        if(s[0][j]==s[1][j]){// tate
            if(prev==-1){
                ans*=3;
            }else if(prev==0){// hidari ga tate
                ans*=2;
            }else{// hidari ga yoko
                ans*=1;
            }
            j++;
            prev=0;
        }else{// yoko
            if(prev==-1){
                ans*=6;
            }else if(prev==0){
                ans*=2;
            }else{
                ans*=3;
            }
            j+=2;
            prev=1;
        }
        ans%=1000000007;
    }

    cout<<ans<<endl;

    return 0;
}