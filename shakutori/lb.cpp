#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    vector<int> v = {1, 2, 3, 4, 5};
    auto it = lower_bound(v.begin(), v.end(), 7);

    int index = it - v.begin();

    // output, out of range does not emit error!!!
    //   index: 5
    //   value: 0
    cout << "index: " << index << endl;
    cout << "value: " << v[index] << endl;
    return 0;

    return 0;
}