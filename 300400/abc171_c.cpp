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

    ll n;cin>>n;
    vector<char>c(27);// 1-indexed, c[0] has nothing
    for(int i=1;i<=26;i++){
        c[i]='a'+(i-1);
    }
    //for(auto e:c)cout<<e<<endl;

    // Base　26
    string res="";
    while(n>0){
        int d=n%26;
        if(d==0){
            d=26;
            n--;
        }
        res+=c[d];
        n/=26;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

    return 0;
}
