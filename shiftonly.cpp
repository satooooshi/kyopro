#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    cin>>n;

    int a[n];
    int m=1000000001;

    REP(i,n){
        cin>>a[i];
        if(a[i]%2){
            cout<<0<<endl;
            return 0;
        }
        m=min(m,a[i]);
        
    }

    int res=0;
    while(1){
         res++;
        REP(i,n){
            a[i]/=2;
            if(a[i]%2){
                cout<<res<<endl;
                return 0;
            }
        }
    }

    return 0;
}