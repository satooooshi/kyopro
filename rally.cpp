#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    sort(x,x+n);

    int ans=1000000000;
    for(int i=x[0];i<=x[n-1];i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=(x[j]-i)*(x[j]-i);
        }
        ans=min(ans,sum);
    }

    cout<<ans<<endl;


    return 0;
}