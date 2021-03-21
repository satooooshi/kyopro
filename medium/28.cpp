// D - Dice in Line

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,k;
    cin>>n>>k;
    vector<int>p;
    rep(i,n){
        int a;
        cin>>a;
        p.push_back(a);
    }

    int mx=0;
    for(int i=(k-1);i<n;i++){
        int sum=0;
        for(int k=i;k>=i-2;k--)sum+=p[k];
        if(mx<sum){
            mx=sum;
        }
    }

    cout<<(mx+k)/2.0<<endl;

    return 0;
}

