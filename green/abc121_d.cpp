#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){

    ll a,b;cin>>a>>b;

    // can know from the small for loop ...
    //  0^..^odd ==  1,0,1,0,..
    //  0^..even == o^..prev odd + odd
    ll res=0;
    for(int i=0;i<=b;i++){
        res^=i;
        cout<<i<<": "<<bitset<4>(i)<<", "<<bitset<4>(res)<<endl;
    }

    

    return 0;
}