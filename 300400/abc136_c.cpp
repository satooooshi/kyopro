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
    // exeption
    if(a.size()==1){
        cout<<"Yes"<<endl;
        return 0;
    }

    for(int i=n-1;i>0;i--){
        if(a[i-1]<=a[i])continue;
        if(a[i-1]>a[i]){
            a[i-1]--;
        }
        if(a[i-1]>a[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    return 0;
}
