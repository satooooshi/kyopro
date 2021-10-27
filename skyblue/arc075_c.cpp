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

template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* k-th number (k is 0-indexed) */
    int get(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main() {
    int N;
    long long K;
    cin >> N >> K;
    //  算術平均が K 以上 ==  Sigma[i:0,n-1](ai-K)が０以上
    //  Sigma[i:l,r-1](ai-K) >= 0 
    //  Sigma[i:l,r-1](ai) >= (r-l)K
    // bl<=br 
    // es r
    // br以下のblの個数をbr[]をインクリメントしながらカウント(es br[])-->転倒数BIT
    vector<long long> S(N+1, 0); // br
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        S[i+1] = S[i] + (a - K);
    }

    // compress
    vector<long long> SS = S;
    sort(SS.begin(), SS.end());
    SS.erase(unique(SS.begin(), SS.end()), SS.end());
    for(int i=0;i<N+1;i++)S[i]=lower_bound(all(SS),S[i])-SS.begin();
    long long res = 0;
    BIT<long long> bit(N+10);
    for (int i = 0; i < N+1; ++i) {
        res += bit.sum(S[i]+1);
        bit.add(S[i]+1, 1);
    }
    cout << res << endl;
}