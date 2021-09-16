#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// UF or map, nC2==Sigma[i:1,n-1]i==n(n-1)/2

int main() {

    int n;cin>>n;
    map<int,int>m;
    ll res=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        a=a%200;
        res+=m[a];
        m[a]++;

    }
    cout<<res<<endl;
    return 0;
}