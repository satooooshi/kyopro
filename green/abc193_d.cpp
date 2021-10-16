#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 繰り返し二乗法 pow(x,n) x^n
// 時間計算量: 𝑂(log𝑛) 空間計算量: 𝑂(1)
//
//const int MOD = 1000000007;
const int MOD = 1;
long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}
int main() {
    int k;cin>>k;
    string s,t;cin>>s>>t;
    map<int,int>ms,mt;
    for(char e:s){
        ms[e-'0']++;
    }
    for(auto e:t){
        mt[e-'0']++;
    }

    vector<ll>pow10(10);// 10^0 to 10^9
    for(int i=0;i<10;i++){
        pow10[i]=pow(10,i);
    }
    //for(auto e:pow10)cout<<e<<endl;cout<<endl;

    ll sp_origin=0,tp_origin=0;
    for(int i=1;i<10;i++){
        sp_origin+=i*pow10[ms[i]];
        tp_origin+=i*pow10[mt[i]];
    }
    //cout<<sp_origin<<" "<<tp_origin<<endl;

    double cnt=0;
    double denominator=0;//(9*k-8)*(9*k-9);
    // count numerator(cnt)
    for(int i=1;i<10;i++){ // s 5 th card i
        if(ms[i]+1>k)continue;
        ll sp=sp_origin;
        sp=sp-i*pow10[ms[i]]+i*pow10[ms[i]+1];
        for(int j=1;j<10;j++){ // t 5 th card j
            if(i==j)if(ms[i]+mt[j]+2>k)continue;
            if(mt[j]+1>k)continue;
            ll tp=tp_origin;
            tp=tp-j*pow10[mt[j]]+j*pow10[mt[j]+1];
            //cout<<i<<":"<<sp<<", "<<j<<":"<<tp<<endl;
            denominator++;
            if(sp>tp){
                cnt++;
            }
        }
    }
    //cout<<cnt<<endl;
    cout << fixed << setprecision(10);
    cout<<1.0*cnt/denominator<<endl;
    return 0;
}