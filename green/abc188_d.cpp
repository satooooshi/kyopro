#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll solve(ll n, ll sp, vector<ll> &a, vector<ll> &b, vector<ll> &c){
    map<ll, ll> memo;
    for(int i = 0; i < n; i++){
        memo[a[i]] += c[i];
        memo[b[i]+1] -= c[i];
    }

    ll ans = 0;
    ll bday = memo.begin()->first;
    ll cursum = 0;
    for(auto &p: memo){
        ll aday = p.first;
        ll add = p.second;
        ans += (aday-bday)*min(sp, cursum);
        cursum += add;
        bday = aday;
    }
    return ans;
}

// zaatu by map, imos, shakutori(cursum+=add)
// https://blog.manuel1024.com/archives/146
int main(){
    ll n, sp;
    cin >> n >> sp;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    cout << solve(n, sp, a, b, c) << endl;
    return 0;
}