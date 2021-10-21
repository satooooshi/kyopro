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
    vector<int>m(n),a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    
    ll sum=0;
    for(int i=0;i<n;i++){
        if(i%2)sum+=(-1)*a[i];
        else sum+=a[i];
    }
    m[0]=sum;// m0=sigma(ai)
    for(int i=n-1;i>=0;i--){
        m[i]=2*a[i]-m[(i+1)%n];
    }

    for(auto e:m)cout<<e<<" ";cout<<endl;

    return 0;
}
