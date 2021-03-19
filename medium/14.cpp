// C - Grid Repainting 2 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int h,w;
vector<vector<char>>s(h);
vector<int>dist(w*h);
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

bool bfs(int sv){
    // debug
    // cout<<"sv:"<<s[sv/w][sv%w]<<" ("<<sv%w<<","<<sv/w<<")"<<endl;
    queue<int>q;
    dist[sv]=0;
    q.push(sv);
    bool ok=false;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        // debug
        // cout<<"v: "<<s[v/w][v%w]<<" ("<<v%w<<","<<v/w<<")"<<endl;
        for(int i=0;i<4;i++){
            int nx=v%w+dx[i];
            int ny=v/w+dy[i];
            int nv=ny*w+nx;
            if(nx<0||nx>=w||ny<0||ny>=h)continue;
            //if(s[ny][nx]=='#'){cout<<"skiped: "<<s[ny][nx]<<" ("<<nx<<","<<ny<<endl;continue;}
            if(s[ny][nx]!='#')continue;
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            // cout<<s[ny][nx]<<" ("<<nx<<","<<ny<<") -> ";
            //cout<<"), d:"<<dist[nv]<<endl;
            q.push(nv);
            ok=true;
        }
    }

    return ok;
}

int main(){

    cin>>h>>w;
    s.resize(h);
    dist.resize(h*w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            s[i].push_back(c);
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i*w+j]=-1;// not visited yet
        }
    }

    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#' && dist[i*w+j]==-1 && !bfs(i*w+j)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;


    return 0;
}