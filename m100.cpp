#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    ll n;
    cin>>n;
    vector<ll>v(n,0);//0 to n-1
    for(int i=0;i<n;i++){
       cin>>v[i];
    }
    vector<ll>o(n/2,0);
    vector<ll>e(n/2,0);
    for(ll i=0,j=0;i<n;i+=2,j++){
        e[j]=v[i];
    }
    for(ll i=1,j=0;i<n;i+=2,j++){
        o[j]=v[i];
    }

    vector<ll>be(n+1,0);
    vector<ll>bo(n+1,0);
    for(ll i=0;i<n/2;i++){
        be[e[i]]++;
    }
    for(ll i=0;i<n/2;i++){
        bo[o[i]]++;
    }

    ll emax=0,omax=0;
    for(ll i=0;i<n/2;i++){
       // cout<<"e:"<<e[i];
        if(be[e[i]]>be[emax])emax=e[i];
    }
    for(ll i=0;i<n/2;i++){
        //cout<<"o:"<<o[i];
        if(bo[o[i]]>bo[omax])omax=o[i];
    }

    //cout<<emax<<":"<<omax<<endl;
    if(omax==emax){
        cout<<n/2<<endl;
    }else{
        cout<<(n/2-be[emax])+(n/2-bo[omax])<<endl;
    }


    return 0;
}
