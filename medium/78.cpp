// A - Connection and Disconnection
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    string s;
    ll k;
    cin>>s>>k;
    int n=s.length();
    vector<int>num(26,0);
    vector<pair<int,int>>a; // {left, cnt}

    if(n==1){ // a
        cout<<k/2<<endl;
        return 0;
    }

    int l=0;
    for(int i=1;i<n;i++){
        while(s[i-1]==s[i])i++;
        int r=i;
        //cout<<s[r-1]<<", left:"<<l<<", cnt:"<<r-l<<endl;
        a.push_back({l,r-l});
        l=r;
    }


    if(a.size()==1){ // aaaaaa
        cout<<n*k/2<<endl;
        return 0;
    }

    ll ca=0;
    for(auto p:a){
        ca+=p.second/2;
    }
    //cout<<"ca:"<<ca<<endl;

    ll cb=0;
    for(int i=1;i<a.size()-1;i++){
        cb+=a[i].second/2;
    }
    //cout<<"cb:"<<cb<<endl;

    ll cc=(a[0].second+a[a.size()-1].second)/2;
    //cout<<"cc:"<<cc<<endl;

    ll res=0;
    if(s[0]!=s[n-1]){ // abcd
        res=ca*k;
    }else{ // aabbaaaa
        res=a[0].second/2+cb*k+cc*(k-1)+a[a.size()-1].second/2;
    }
    

    cout<<res<<endl;
    


    return 0;
}