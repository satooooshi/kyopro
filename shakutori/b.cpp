#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    string s;
    int k;
    cin>>s>>k;
    map<string,int>m;
    if(s.length()==k)cout<<1<<endl;
    else if(s.length()<k)cout<<0<<endl;
    else{
        for(int i=0;i<s.length();i++){
           if(i+k<=s.length())
                m[s.substr(i,k)]++;

        }
        cout<<m.size()<<endl;
    }

    return 0;
}