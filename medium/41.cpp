// A - Shrinking
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


// kinda run length
int main(){

    string s;
    cin>>s;
    int res=101;
    for(int i=0;i<s.length();i++){
        int chi=i;
        int d=0;
        for(int j=0;j<s.length();j++){
            if(s[chi]!=s[j]){
                d=max(d,abs(j-chi));
            }else{
                chi=j;
            }
        }
        res=min(res,d);
    }

    cout<<res<<endl;


    return 0;
}
