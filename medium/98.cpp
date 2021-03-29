// C - Product and GCD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll n,p;
    cin>>n>>p;
    const auto &res = prime_factorize(p);
    //cout << p << ":";for (auto p : res) {for (int i = 0; i < p.second; ++i) cout << " " << p.first;}cout << endl;
    ll ans=1;    
    for (auto p : res){
        if(p.second>=n){
            for (int j = 0; j < p.second/n; ++j) ans *= p.first;// ex. n==3, 2^8, give 2 two to each ai
        }
    }
    cout<<ans<<endl;
}