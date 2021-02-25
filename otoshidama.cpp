#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){
    
    ll n,y;
    cin>>n>>y;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                 if( (i+j+k==n) && (i*10000+j*5000+k*1000==y) ){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<-1<<" "<<-1<<" "<<-1<<endl;


    return 0;
}