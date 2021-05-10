#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    string s;
    cin>>s;

    for(int i=0;i<10;i++){
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        if(tmp==s){
            cout<<"Yes"<<endl;
            return 0;
        }
        s='0'+s;
        //cout<<s<<endl;
    }
    cout<<"No"<<endl;
    

    return 0;
}