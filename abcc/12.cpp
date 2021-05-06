// C - Bowls and Dishes 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m),b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
    }
    int k;
    cin>>k;
    vector<int>c(k),d(k);
    rep(i,k){
        cin>>c[i]>>d[i];
    }

    int ans=0;
    for(int bit=0;bit<(1<<k);bit++){ // 0:put d, 1:put c
        vector<int>dishes(n);
        int cnt=0;
        for(int i=0;i<k;i++){ // k people
            if(bit&(1<<i)){
                dishes[c[i]-1]++;
            }else{
                dishes[d[i]-1]++;
            }
        }

        for(int i=0;i<m;i++){
            if(dishes[a[i]-1]>=1&&dishes[b[i]-1]>=1){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;

    
    return 0;
}

