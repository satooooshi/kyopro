#include <iostream>
using namespace std;
int H, W, A, B, ans = 0;
void dfs(int i, int bit, int A, int B){
    // bit set already tatami is placed @ i[0,HW)
    // row0[0,w)row1[w,2*w)..[,HW)
    if(i == H * W){ans++;return;}//return (void)ans++;// 
    if(bit & 1 << i) return dfs(i + 1, bit, A, B);
    // 正方形
    if(B) dfs(i + 1, bit | 1 << i, A, B - 1);
    // 長方形のタイル
    if(A){
        // 右に伸ばす
        if(i % W != W - 1 && ~bit & 1 << (i + 1)) dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
        // 下に伸ばす
        if(i + W < H * W) dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
    }
}
int main(){
    cin >> H >> W >> A >> B;

    // 長方形の畳の左上となる場所を決め、そこから右か下かどちらに伸ばす
    dfs(0, 0, A, B);
    cout << ans << endl;
}