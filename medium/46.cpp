// B - Palindrome-phobia
// aa 
// aba
// the same character should have offset of at least 2
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
    map<char,int>m;
    for(auto c:s){
        m[c]++;
    }
    int pc=min(m['a'],min(m['b'],m['c']));
    m['a']-=pc;
    m['b']-=pc;
    m['c']-=pc;
    if(m['a']>1||m['b']>1||m['c']>1){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    return 0;
}
