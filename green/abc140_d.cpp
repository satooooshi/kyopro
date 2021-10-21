#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n,k;cin>>n>>k;
    string s;cin>>s;

    int cnt=0;
    int unh=0;
    if(s[0]=='L')unh++;
    for(int i=1;i<n;i++){
        if(s[i-1]=='R'&&s[i]=='L'){
            cnt+=2;
        }
    }
    if(s[n-1]=='R')unh++;

    while(k--&&cnt-2>=0){
        cnt-=2;
    }

    while(k--&&unh--){
        // do nothing;
    }
    cout<<n-cnt-unh<<endl;

    return 0;
}
