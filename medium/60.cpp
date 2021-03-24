#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // 64-bit long
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    string march="MARCH";
    map<char,int>m;
    rep(i,n){
        string s;
        cin>>s;
        m[s[0]]++;
    }
    
    

    //for(auto a:m)cout<<a.first<<" "<<a.second<<endl;
    ll cnt=0;
    // 5C3
    for(int i=0;i<march.length();i++){
        for(int j=i+1;j<march.length();j++){
            for(int k=j+1;k<march.length();k++){
                cnt+=1LL*m[march[i]]*m[march[j]]*m[march[k]];// m[] returns int !! has to convert to long long with 1LL!!
            }
        }
    }
    cout<<cnt<<endl;


    return 0;
}

