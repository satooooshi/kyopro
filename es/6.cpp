#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int a,b,k;
    cin>>a>>b>>k;

    int cnt=0;
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0&&b%i==0)cnt++;

        if(cnt==k){
            cout<<i<<endl;
            return 0;
        }
    }


    return 0;
}
