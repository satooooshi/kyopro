#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    ll n;
    cin>>n;

    map<int,int>m;
    ll a[n];
    ll combi=0;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a[i]=x;
        combi+=m[x];
        m[x]++;
    }

    for(ll i=0;i<n;i++){
        cout<<combi-(m[a[i]]-1)<<endl;
    }


    return 0;
}