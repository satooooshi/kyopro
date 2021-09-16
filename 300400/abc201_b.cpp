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
    vector<pair<int,string>>a;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int t;cin>>t;
        a.push_back({t,s});
    }

    sort(a.begin(),a.end());
    cout<<a[n-2].second<<endl;
    return 0;
}