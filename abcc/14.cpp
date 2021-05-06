// C - Forbidden List
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    set<int>s;
    int x,n;
    cin>>x>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }

    int mn=x;
    for(int i=x-100;i<=x+100;i++){
        if(s.find(i)== s.end()){
            mn=min(mn,abs(i-x));
            cout<<i<<"-"<<x<<"="<<abs(i-x)<<endl;
        }
    }
    cout<<mn+x<<endl;

    return 0;
}
