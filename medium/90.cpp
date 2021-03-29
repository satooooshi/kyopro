// C - GeT AC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll>a(n);
    a[0]=0;
    for(int i=1;i<n;i++){
        if(s[i-1]=='A'&&s[i]=='C'){
            a[i]=a[i-1]+1;
        }else{
            a[i]=a[i-1];
        }
    }
    //for(auto x:a){cout<<x<<" ";}cout<<endl;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--; // 0 based indexing
        r--;
        cout<<a[r]-a[l]<<endl;
    }

    


    return 0;
}
