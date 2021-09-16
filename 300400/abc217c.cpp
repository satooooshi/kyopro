#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

/* backet indexing
for(int i=1;i<=n;i++)// 1-indexed
    q[] (disecrete):=i (successive)
*/

int main() {

    ll n;
    cin>>n;
    vector<ll>q(n+1);// 1-indexed
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        q[x]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<q[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;

    return 0;
}