// B - Evilator
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s;
    while(cin>>s){
    int n=s.length();

    ll cnt=0; // 10^5*10^5
    for(int i=1;i<n+1;i++){
        if(s[i-1]=='U'){
            cnt+=(i-1)*2+(n-i)*1;
        }else{ // s[i-1]=='D'
            cnt+=(i-1)*1+(n-i)*2;
        }
    }
    cout<<cnt<<endl;
    }


    return 0;
}
