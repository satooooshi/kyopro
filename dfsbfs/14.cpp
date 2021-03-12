// buy an integer
#include <bits/stdc++.h>
using namespace std;

auto d(long long N){
    long long res = 0;
    while (N) ++res, N /= 10;
    return res;
}

auto f(long long N, long long A, long long B, long long X) {
    return A * N + B * d(N) > X;
}

int main() {
    long long A, B, X;
    cin >> A >> B >> X;
    // binary search
    long long left = 0, right = 1000000001;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (f(mid, A, B, X)) right = mid;
        else left = mid; // ( f(mid)≤Xを満たす最大の正の整数mid )
    }
    cout << left << endl;
}