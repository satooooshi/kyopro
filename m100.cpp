#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    ll n;
    cin>>n;
    vector<ll>v(n,0);//0 to n-1
    vector<ll>be(100000+1000,0);
    vector<ll>bo(100000+1000,0);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    //cout<<"hello"<<endl;

    
    for(ll i=0;i<n;i+=2){
        be[v[i]]++;
    }
    for(ll i=1;i<n;i+=2){
        bo[v[i]]++;
    }

    ll emax=1,omax=1;
    for(ll i=1;i<=100000+1000;i++){
        //cout<<"e:"<<be[i];
        if(be[i]>be[emax])emax=i;
    }
    for(ll i=1;i<=100000+1000;i++){
        //cout<<"o:"<<o[i];
        if(bo[i]>bo[omax])omax=i;
    }

    //cout<<emax<<":"<<omax<<endl;
    if( (omax==emax)&&(bo[omax]==n/2&&be[emax]==n/2)){
        cout<<n/2<<endl;
    }else{
        cout<<(n/2-be[emax])+(n/2-bo[omax])<<endl;
    }


    return 0;
}
