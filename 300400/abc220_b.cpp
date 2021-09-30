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

    int k;
    string a,b;
    cin>>k>>a>>b;

    ll x=1,va=0;
    for(int i=a.length()-1;i>=0;i--){
        va+=(a[i]-'0')*x;
        x*=k;
    }

    x=1;
    ll vb=0;
    for(int i=b.length()-1;i>=0;i--){
        vb+=(b[i]-'0')*x;
        x*=k;
    }
    cout<<va*vb<<endl;

    return 0;
}
