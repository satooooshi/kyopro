// C - Minimization
#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;

int main() {
  while (cin >> N >> K) {
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int res = 0;
    int right = 0;
    while (true) {
      if (res == 0) right += K;
      else right += K-1;
      ++res;

      if (right >= N) break;
    }
    cout << res << endl;
  }

  return 0;
}