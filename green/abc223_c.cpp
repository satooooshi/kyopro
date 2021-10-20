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
    vector<double>a(n),b(n);

    double t=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        t+=1.0*a[i]/b[i];
    }
    t/=2; // 2つの導火線が 巡り会うまでの時間t

    int i=0;
    double x=0;
    while(t>0){
        t-=a[i]/b[i];
        x+=a[i];
        i++;
    }
    double dt=t;
    x+=b[i-1]*dt;

    cout << fixed << setprecision(10);
    cout<<x<<endl;

    return 0;
}

