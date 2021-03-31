// A - Biscuits
// https://drken1215.hatenablog.com/entry/2020/04/09/150100
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;



int main() {
    int N, P;
    cin >> N >> P;
    int m = 0;
    for (int i = 0; i < N; ++i) {
        int A; cin >> A;
        if (A % 2 == 1) ++m;
    }
    if (m == 0) cout << (P == 0 ? (1LL<<N) : 0) << endl;
    else cout << (1LL<<(N-1)) << endl;
}

/* buggy!!
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

int main(){

    int n,p;
    cin>>n>>p;
    int o=0,e=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a&1){
            o++;
        }else{
            e++;
        }
    }

    COMinit();

    // p==0: 全て偶数　または　偶数個を任意袋数と奇数を偶数袋数
    ll cnt=0;
    for(int i=0;i<=e;i++){
        for(int j=0;j<=o;j+=2){
            cnt+=COM(e,i)*COM(o,j);
        }
    }
    if(p==0)cout<<cnt<<endl;
    else{
        cnt=(pow(2,n)-cnt);
        cout<<cnt<<endl;
    } 

    return 0;
}
*/

/*
// bit not enough need N:50 bits!!
int main(){

   
    int n,p;
    cin>>n>>p;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }
    ll res=0;
    for(ll bit=0;bit<(1<<n);bit++){
        ll x=0;
        for(int i=0;i<n;i++){
            if(!(bit&(1<<i)))continue;
            x+=a[i];
        }
        if(x%2==p)res++;
    }
    cout<<res<<endl;



    return 0;
}
*/

