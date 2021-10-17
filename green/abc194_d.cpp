#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;cin>>n;
    
    double ans=0;
    for(int i=n-1;i>=1;i--){
        ans+=1.0*n/i;
    }
    cout << fixed << setprecision(10);
    cout<<ans<<endl;

    return 0;
}