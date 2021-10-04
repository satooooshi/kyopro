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

    int k;cin>>k;
    vector<int>a(10*k);
    // ai ≡ 0 mod k --> ai%k is in [0,k) hatonosu-gennri, otherwise doesnt exist
    a[0]=7%k;
    if(a[0]==0){
        cout<<1<<endl;
        return 0;
    } 
    for(int i=0;i<=k;i++){
        a[i+1]=10*a[i]+7;
        a[i+1]%=k;
        //cout<<a[i+1]<<endl;
        if(a[i+1]==0){
            cout<<i+1+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
