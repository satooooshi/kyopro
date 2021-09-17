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

    ll n,k;// k is 10^18 long long
    cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    vector<int>b=v;

    sort(v.begin(),v.end());

    ll offset=k/n;
    ll rem=k%n;
    ll lim=v[rem];// sentinel
    for(int i=0;i<n;i++){
        if(b[i]<lim){
            cout<<offset+1<<endl;
        }else{
            cout<<offset<<endl;
        }
    }
 
    return 0;
}
