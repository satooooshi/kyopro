// B keyence string

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string s;
    cin>>s;
    int n=s.length();

    // leftの文字列の文字数、rightの文字列の開始地点
    for(int left=0;left<n;left++){
        for(int right=left;right<n;right++){
            string t=s.substr(0,left)+s.substr(right);
            //cout<<t<<endl;
            if(t=="keyence"){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;


    return 0;
}