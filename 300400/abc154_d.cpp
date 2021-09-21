#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n,k;cin>>n>>k;
    vector<double>e(n);

    // expectations of dice i
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        // implicit casting
        e[i]=1.0*(1+p)/2;
    }

    // cusum
    vector<double> s(n+1, 0); // s[0] = 0 になる
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + e[i];

    double res=-1;
    // [i-k,i)
    for(int i=k;i<n+1;i++){
        //cout<<"["<<i-k<<","<<i<<"):"<<s[i]-s[i-k]<<endl;
        res=max(res,s[i]-s[i-k]);
    }

    cout << fixed << setprecision(10);
    cout<<res<<endl;




    return 0;
}
