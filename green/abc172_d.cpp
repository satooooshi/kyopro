#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;cin>>n;
    vector<int>f(n);
    for(int k=1;k<=n;k++){
        f[k]=n/k;
    }
    // eratos の表、横軸divs,縦軸k,調和級数的計算量 O(Nlog2N)
    long long res=0;
    for(int a=1;a<=n;a++){ // k's div
        for(int b=a;b<=n;b+=a){ 
            res+=b;
        }
    }
    cout<<res<<endl;

    return 0;
}
