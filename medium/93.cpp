// C - Switches
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>s(m);
    vector<int>p;
    rep(i,m){
        int k;
        cin>>k;
        rep(j,k){
            int x;
            cin>>x;
            x--;
            s[i].push_back(x);
        }
    }
    rep(i,m){
        int x;
        cin>>x;
        p.push_back(x);
    }
/*
    rep(i,m){
        rep(j,s[i].size()){
            cout<<s[i][j]<<" ";
        }cout<<endl;
    }
*/

//bitES
ll res=0;
for(int bit=0;bit<(1<<n);bit++){ // bit set means switch is on, otherwise off

    bool ok=true;
    for(int i=0;i<m;i++){ // ith bulb
        int cnt=0; // cnt of switches on
        for(int j=0;j<s[i].size();j++){ // jth switch of ith bulb
            if(bit&(1<<s[i][j])){ // ith switch is of ith bulb is on
                cnt++;
            }
        }
        if(cnt%2!=p[i]){
            ok=false;
            break;    
        }
    }
    if(ok)res++;
}

cout<<res<<endl;

    return 0;
}
