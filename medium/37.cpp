#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>h(n);
    rep(i,n)cin>>h[i];

    int cnt=0;
    while(true){
        int i=0;
        while(i<n&&h[i]==0)i++;
        if(i==n)break; // now all zero
        int l=i;
        while(i<n&&h[i]>0)i++;
        int r=i;
        // [left,right)
        //cout<<"["<<l<<","<<r<<")"<<endl;
        int j=l;
        while(j<r){h[j]--;j++;}
        cnt++;
    }

    cout<<cnt<<endl;


    return 0;
}

