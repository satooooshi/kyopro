#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    cin>>n;
    n++;
    int t[n]{},x[n]{},y[n]{};
    t[0]=0;
    x[0]=0;
    t[0]=0;

    for(int i=1;i<n;i++){
        cin>>t[i]>>x[i]>>y[i];
    }

    for(int i=1;i<n;i++){
        int dt=t[i]-t[i-1];
        int dist=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        if(dt<dist || dt%2==0&&dist%2!=0 || dt%2!=0&&dist%2==0){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;


    return 0;
}