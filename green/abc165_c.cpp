#include <bits/stdc++.h>
using namespace std;

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


// 深さ優先探索 dfs O(V+E)
using Graph = vector<vector<int>>;
vector<bool> seen;  // 既に見たことがある頂点か記録

int n,m,q;
vector<int>a,b,c,d;
vector<int>res;

int check(){
    if(res[n-1]==-1)return -1;
    int ret=0;
    for(int i=0;i<q;i++){
        if(res[b[i]]-res[a[i]]==c[i]){
            ret+=d[i];
        }
    }
    return ret;
}

int dfs(int i, int d) {

    if(i>=n){
        return check();
    }

    int ret=-1;
    for(int num=d;num<=m;num++){
        res[i]=num;
        ret=max( ret, dfs(i+1,num) );
        res[i]=-1;
    }

    return ret;
}
int main() {
    cin>>n>>m>>q;
    res.assign(n,-1);
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i=0;i<q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--; // 0-based
        b[i]--;
    }

    cout<<dfs(0,1)<<endl;

    return 0;
}