// C - 4-adjacent#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    int cf=0,ct=0,ce=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a%4==0){
            cf++;
        }else if(a%2==0){
            ct++;
        }else{
            ce++;
        }
    }
    //cout<<cf<<","<<ct<<","<<ce<<endl;
    // ignore cts 
    ce+=(ct%2);

    if(ce<=cf+1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

