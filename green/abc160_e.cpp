#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {

    int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<int>p(a),q(b),r(c);
    vector<int>vec;
    for(auto &e:p)cin>>e;
    for(auto &e:q)cin>>e;
    for(auto &e:r)cin>>e;
    sort(p.begin(),p.end(), greater<int>());
    sort(q.begin(),q.end(), greater<int>());
    for(int i=0;i<x;i++)vec.push_back(p[i]);
    for(int i=0;i<y;i++)vec.push_back(q[i]);
    sort(r.begin(),r.end(),greater<int>());
    vector<ll>sr(c+1,0);
    for(int i=0;i<c+1;i++){
        sr[i+1]=sr[i]+r[i];
    }    
    sort(vec.begin(),vec.end());
    //for(auto e:vec)cout<<e<<endl;

    ll tot=accumulate(vec.begin(),vec.end(),0);
    vector<ll>sab(x+y+1,0);
    for(int i=0;i<x+y+1;i++){
        sab[i+1]=sab[i]+vec[i];
    }
    

    ll res=-1;
    for(int i=0;i<max(x+y,c);i++){
        res=max(res,tot-sab[i]+sr[i]);
    }
    cout<<res<<endl;



    return 0;
 }
