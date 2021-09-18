#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll res=inf;
    for(int bit=0;bit<(1<<(n-1));bit++){
        ll ore=0;
        ll xore=0;
        for(int i=0;i<(n-1);i++){// left-most elem is i0, or bit0001==A0
            ore|=a[i];
            if(bit&(1<<i)){
                xore^=ore;
                ore=0;
            }  
        }
        // last elem (right-most elem)
        ore|=a[n-1];
        xore^=ore;
        res=min(res,xore);
    }

    cout<<res<<endl;


    return 0;
}
