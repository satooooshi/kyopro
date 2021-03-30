// C - /\/\/\/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    int n;
    cin>>n;
    map<int,int>me,mo;
    rep(i,n){
       int x;
       cin>>x;
       if(i%2)mo[x]++;
       else me[x]++;
    }
    // max count
    int mxo=-1,o=-1,mxe=-1,e=-1;
    for(auto p:mo){
        if(mxo<p.second){
            mxo=p.second;
            o=p.first;
        }
    }
    for(auto p:me){
        if(mxe<p.second){
            mxe=p.second;
            e=p.first;
        }
    }
    // second max count
    int smxo=-1,so=-1,smxe=-1,se=-1;
    for(auto p:mo){
        if(p.first==o)continue;
        if(smxo<p.second){
            smxo=p.second;
            so=p.first;
        }
    }
    for(auto p:me){
        if(p.first==e)continue;
        if(smxe<p.second){
            smxe=p.second;
            se=p.first;
        }
    }

    //cout<<"o:"<<o<<" "<<mxo<<" ko, e:"<<e<<" "<<mxe<<" ko"<<endl;
    //cout<<"so:"<<so<<" "<<smxo<<" ko, se:"<<se<<" "<<smxe<<" ko"<<endl;


    if(o==e){
        // all same num ex. all 1s
        if(mxo==mxe){
            cout<<n/2<<endl;
            return 0;
        }
        if(mxo<mxe){
            cout<<n-mxe-smxo<<endl;
        }else{
            cout<<n-mxo-smxe<<endl;
        }
    }
    else
    {
        cout<<n-mxo-mxe<<endl;
    }
    

    return 0;
}
