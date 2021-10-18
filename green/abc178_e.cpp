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

    int n;cin>>n;
    vector<int>a(n),b(n); // x+y, x-y
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        a[i]=x+y;
        b[i]=x-y;
    }
    sort(all(a));
    sort(all(b));

    cout<<max((a.back()-a[0]),(b.back()-b[0]))<<endl;

    
    return 0;
}
