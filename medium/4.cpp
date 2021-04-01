// B. ss
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    string s;
    cin>>s;
    int len=s.length()/2;
    len--;
    while(len>0){
        //cout<<len<<", "<<s.substr(0,len)<<":"<<s.substr(len,len)<<endl;
        if(s.substr(0,len)==s.substr(len,len)){
            cout<<s.substr(0,len).length()*2<<endl;
            return 0;
        }
        len--;
    }


    return 0;
}


