// B - バイナリハックイージー
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string s;
    cin>>s;
    string t;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'||s[i]=='1'){
            t+=s[i];
        }else{
            int len=t.length()==0?0:(t.length()-1);
            t=t.substr(0,len);
        }
        //cout<<"si"<<s[i]<<",t:"<<t<<endl;
    }

    cout<<t<<endl;



    return 0;
}
