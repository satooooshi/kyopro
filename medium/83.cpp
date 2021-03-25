// A - Limited Insertion
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>v(n+1);// 1 based indexing, dont use v[0]
    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }

    if(v[1]!=1){
        cout<<-1<<endl;
        return 0;
    }

    int mx=v[1];
    for(int i=2;i<n+1;i++){
        mx=max(mx,v[i]);
        if(mx>i){
            cout<<-1<<endl;
            return 0;
        }
    }

    sort(v.begin()+1,v.end());
    for(int i=1;i<n+1;i++)cout<<v[i]<<endl;





    return 0;
}
