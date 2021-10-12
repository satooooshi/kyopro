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

    if (k == 0) {
        cout << 1ll*n*n << endl;
        return 0;
    }

    ll res=0;
    for(int b=1;b<=n;b++){
        if(b<=k)continue;
        ll cnt=b-k;
        ll p=(n)/b;//ll p=(n+1)/b; n+1 when consider from a==0 ex. 0%b,1%b,..
        cnt=cnt*p;
        ll l=(b*p+k);
        ll r=n;
        if(l<=r)cnt+=r-l+1;
        res+=cnt;
    }
    cout<<res<<endl;
    return 0;
}
