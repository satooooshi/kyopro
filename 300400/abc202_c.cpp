#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n;cin>>n;
    // 1-indexed
    //vector<int>a(n+1);
    map<int,int>acnt; // {ai, #ais}
    map<int,vector<int>>m; // {bi, #biindexes}
    map<int,int>ccnt;

    for(int i=1;i<=n;i++){
        int a;cin>>a;
        acnt[a]++;
    }
    for(int i=1;i<=n;i++){
        int b;cin>>b;
        m[b].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int c;cin>>c;
        ccnt[c]++;
    }

    ll res=0;
    for( auto i = acnt.begin(); i != acnt.end() ; ++i ) {
        for(auto e : m[i->first]){ // m[a[i]].size()==#indexes of  value ai in arrray b
            res+=i->second*ccnt[e];
        }
    }
    cout<<res<<endl;


    return 0;
}