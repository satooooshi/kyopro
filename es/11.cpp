#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>p(n),q(n);
    for(int i=0;i<n;i++)cin>>p[i],--p[i];// 0-based indexing
    for(int i=0;i<n;i++)cin>>q[i],--q[i];
    vector<int>a(n);
    iota(a.begin(),a.end(),0);
    map<vector<int>,int>m;
    int i=0;
    do{
        m[a]=i++;
    }while(next_permutation(a.begin(),a.end()));

    cout<<abs(m[p]-m[q])<<endl;

    return 0;
}
