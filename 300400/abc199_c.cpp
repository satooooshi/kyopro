#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n;cin>>n;
    string s;cin>>s;
    int q;cin>>q;
    int flag=0;// 1 means flipped
    for(int i=0;i<q;i++){
        int t,a,b;// 0-indexed
        cin>>t>>a>>b;
        a--;
        b--;
        if(t==1){
            if(flag){
                a=(a+n)%(2*n);
                b=(b+n)%(2*n);
            }
            swap(s[a],s[b]);
        }else{
            flag=(1-flag);
        }
    }

    if(flag){
        cout<<s.substr(n,2*n)+s.substr(0,n)<<endl;
    }else{
        cout<<s<<endl;
    }
    

    return 0;
}