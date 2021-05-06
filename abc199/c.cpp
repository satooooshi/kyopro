#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;

    string res=s;
    bool rv=false;
    for(int i=0;i<q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        t--;
        a--;
        b--;
        if(t){//t2
            rv=!rv;
        }else{//t1
            if(rv){
                a=(a+n)%(2*n);
                b=(b+n)%(2*n);
                //cout<<a<<":"<<b<<endl;
            }
            char tmp=res[a];
            res[a]=res[b];
            res[b]=tmp;
        }

    }

    if(rv){
        cout<<res.substr(n,n)+res.substr(0,n)<<endl;
    }else
        cout<<res<<endl;

    return 0;
}
