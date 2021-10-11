#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {

        int n; ll k; cin >> n>>k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        /* 区間の長さの最小値 */
        ll res = 0; // 上界を入れておく

        /* 区間の左端 left で場合分け */
        int right = 0;
        long long sum = 0;
        for (int left = 0; left < n; ++left) {
            /* [left, right) の総和が x 以上となる最小の right を求める */
            while (right < n && sum < k) {
                sum += a[right];
                ++right;
            }

            /* 更新 */
            if (sum < k) break; // これ以上 left を進めてもダメ
            res+=(n-right+1);
            //cout<<left<<", "<<right<<": "<<endl;

            /* left をインクリメントする準備 */
            if (right == left) ++right; // right が left に重なったら right も動かす
            else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
        }

        cout<<res<<endl;

        return 0;
}