#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    string s;cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='9'){
            s[i]='6';
        }else if(s[i]=='6'){
            s[i]='9';
        }
    }
    cout<<s<<endl;


    return 0;
}