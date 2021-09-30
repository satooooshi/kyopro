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

int n;
vector<int>h(n);
queue<pair<int,int>>q;

// interval bfs
int bfs(int l, int r, int offset){
    int res=0;
    q.push({l,r});
    
    while(q.size()){
        int nl=q.front().first;
        int nr=q.front().second;
        q.pop();
        int i=nl;
        while(nl<nr){
        while(h[i]-offset<=0&&i<nr)i++;
        nl=i;
        while(h[i]-offset>0&&i<nr)i++;
        nr=i;
        
        if(nl<nr)cout<<nl<<","<<nr<<endl,q.push({nl,nr}),res++;
        }
        offset++;
        
    }
    return res;
}


int main(){
    cin>>n;
    h.resize(n);
    for(auto &e:h)cin>>e;
    cout<<bfs(0,n,0)<<endl;//[l,r), 初期値hi==０を考慮
    return 0;
}