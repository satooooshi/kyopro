#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int>>a(n);
    vector<int>b(m);
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=a[i][j]*b[j];
            
        }
        if(sum+c>0)cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}

