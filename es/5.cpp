#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main(){

    int n;
    cin>>n;

    if(n==105)cout<<1<<endl;
    else if(n<105){
        cout<<0<<endl;
    }else{
        int cnt=0;
        for(int i=105;i<=n;i+=2){
            if(enum_divisors(long(i)).size()==8)cnt++;
        }
        cout<<cnt<<endl;
    }


    return 0;
}
