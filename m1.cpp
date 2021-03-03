#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){

    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    ll cnt=1;
    ll x=a[0];
    while(1){
        if(x==1)
            break;//now 0-offset
        //cout<<"x:"<<x<<"cnt:"<<cnt<<endl;
        x=a[x];
        cnt++; 
        if(cnt>n){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}