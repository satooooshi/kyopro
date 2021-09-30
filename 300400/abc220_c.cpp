#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main() {

    int n;cin>>n;
    vector<int>a(n);
    for(auto &e:a)cin>>e;
    ll x;cin>>x;

    // sigma[0,n)ai < x
    ll res=0;
    for(int i=0;i<n;i++){
        res+=a[i];
        if(res>x){
            cout<<i+1<<endl;
            return 0;
        }
    }

    // sigma[0,n)ai >= x
    ll cnt=x/res;
    ll offset=0;
    for(int i=0;i<n;i++){
        offset+=a[i];
        if(cnt*res+offset>x){
            cout<<cnt*n+i+1<<endl;
            return 0;
        }
    }

    return 0;
}
