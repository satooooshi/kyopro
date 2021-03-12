// grid repainting 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int h,w;
    cin>>h>>w;
    vector<vector<char>>s(h);
    vector<int>dist(w*h);
    const vector<int> dx = {-1, 0, 1, 0};
    const vector<int> dy = {0, -1, 0, 1};
    int cw=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char x;
            cin>>x;
            s[i].push_back(x);
            if(x=='.')cw++;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i*w+j]=-1;// not visited
        }
    }

    queue<int>q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=v%w+dx[i];
            int ny=v/w+dy[i];
            int nv=ny*w+nx;
            if(nx<0||nx>=w||ny<0||ny>=h)continue;
            //if(s[ny][nx]=='#'){cout<<"skiped: "<<s[ny][nx]<<" ("<<nx<<","<<ny<<endl;continue;}
            if(s[ny][nx]=='#')continue;
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            //cout<<s[ny][nx]<<" ("<<nx<<","<<ny;
            //cout<<"), d:"<<dist[nv]<<endl;
            q.push(nv);
        }
    }

    if(dist[(h-1)*w+(w-1)]==-1){
        cout<<-1<<endl;
    }else{
        cout<<cw-(dist[(h-1)*w+(w-1)]+1)<<endl;
    }
    


    return 0;
}
