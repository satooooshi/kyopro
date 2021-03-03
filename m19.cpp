#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int r,g,b,n;
    cin>>r>>g>>b>>n;

    ll cnt=0;
    for(int i=0;i<=n/r+1;i++){
        for(int j=0;j<=n/g+1;j++){
            int remain=n-(r*i+g*j);
            if(remain==0)cnt++;
            else if( (remain>0) && (remain%b==0) )cnt++; // prevent minus and divide by zero
            else continue;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
