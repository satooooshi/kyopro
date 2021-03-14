#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;

    for(int i=n/1.08;i<=n;i++){
        if(floor(i*1.08)==n){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<":("<<endl;

/*
buggy
    double left=n/1.08, right=(n+1)/1.08;
    //cout<<left<<","<<right<<endl;
    //cout<<ceil(left)<<","<<floor(right)<<endl;

    if(ceil(left)<=floor(right))cout<<floor(right)<<endl;
    else 

    if(left-ceil(left)>0.0){
        if(right-left>=0){
            cout<<floor(right);
        }else{
            cout<<":("<<endl;
        }
    }else if(right-ceil(right)>0.0){
        
    }
*/

    return 0;
}

