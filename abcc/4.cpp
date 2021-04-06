// C - Duodecim Ferra 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;

// ex. l==14
// l-1C11
// 13*12*11.../1*2*3  can be divisible!!
//「連続する n 個の自然数の積は、かならず n! で割り切れる」
int main() {
    long long L;
    cin >> L;
    long long res = 1;
    for (int i = 1; i <= 11; ++i) {
        res *= L - i;
        res /= i;
    }
    cout << res << endl;
}

/*
can be overflow
// nCk
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();

    ll l;
    cin>>l;

    // 計算例
    // n-1+rCr
    // cout << COM(12-1+l-12, l-12) << endl;
    cout << COM(l-1, 11) << endl;
}
*/