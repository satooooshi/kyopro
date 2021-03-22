//C - Remainder Minimization 2019
// n(n+1)(n+2) は 3 の倍数である==連続する 3 整数には 3 の倍数が含まれる
// 2019 個以上の整数が連続すると、その中に必ず 2019 の倍数がある
//R−L≥2019R−L≥2019 のときは答えが 0 それ以外のときは、全探索できる！！！
//候補数は多く見積もっても (R−L)2(R−L)2 == 2019*2019==4*10^6くらいなので。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll l,r;
    cin>>l>>r;
    if(r-l>=2500){
        cout<<0<<endl;
        return 0;
    }else{
        ll res=2019;
        for(ll i=l;i<=r;i++){
            for(ll j=i+1;j<=r;j++){
                ll m=(i*j)%2019;
                res=min(res,m);
            } 
        }
        cout<<res<<endl;
        return 0;
    }
    
    
    


    return 0;
}