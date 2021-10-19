#include<bits/stdc++.h>
using namespace std;

// O(log2X)
long long GCD(long long x, long long y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

// prime_factorize
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

// aとbの公約数つまり最大公約数g=gcd(a,b)の公約数
// aとbが互いに素つまり共通の素因数を持たない
// つまり素因数の個数が答え
int main() {
    long long a,b;cin>>a>>b;
    vector<pair<long long, long long>>res;
    long long g=GCD(a,b);
    res=prime_factorize(g);
    cout<<res.size()+1<<endl;
    return 0;
}