#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<vector<int>>x(n),y(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            int v1,v2;
            cin>>v1>>v2;
            x[i].push_back(v1-1); // zero-based index
            y[i].push_back(v2);
        }
    }

    int ans=-1;
    for(int bit=0;bit<(1<<n);bit++){ // bitset consists of honest:1, unkind 0
        bool ok=true;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){ // only listen to honest one
                for(int j=0;j<x[i].size();j++){
                    if(y[i][j]==1){
                        if(bit&(1<<x[i][j])){
                            //ok
                        }else{
                            ok=false;
                        }
                    }else{// y[i][j]==0
                        if((~bit)&(1<<x[i][j])){
                            //ok
                        }else{
                            ok=false;
                        }
                    }
                }
            }
        }
        //cout<<":"<<ok<<endl;
        if(!ok)continue;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(bit&(1<<i))cnt++;
        }
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;


    return 0;
}
