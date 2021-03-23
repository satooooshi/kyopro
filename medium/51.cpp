// C - Many Medians
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n;
    cin>>n;
    vector<ll>x(n),y(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        x[i]=a;
        y[i]=a;
    }
    sort(y.begin(),y.end());
    for(int i=0;i<n;i++){
        if(x[i]<y[n/2])cout<<y[n/2]<<" ";
        else cout<<y[n/2-1]<<" ";
    }
    cout<<endl;


    return 0;
}