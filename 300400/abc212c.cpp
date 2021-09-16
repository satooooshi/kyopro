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

    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll res=infl;
    for(int i=0;i<n;i++){
        auto idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(idx<m){
            res=min(res,(ll)abs(a[i]-b[idx]));
        }
        if(idx-1>=0){
            res=min(res,(ll)abs(a[i]-b[idx-1]));
        }
    }

    cout<<res<<endl;

    

    return 0;
}