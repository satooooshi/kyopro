#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){

    int n,a[n];
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    int suma=0,sumb=0;
    for(int i=n-1;i>=0;i--){
        if(i%2==0)
            suma+=a[i];
        else
            sumb+=a[i];
    }

    cout<<abs(suma-sumb)<<endl;

    return 0;
}
