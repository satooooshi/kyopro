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

// Aiの中にKの倍数 --> Ai≡0 mod K, mod Kの値は[0,k)で循環

int main() {
    int k;cin>>k;
    vector<ll>a(k+10);
    for(int i=0;i<(k+10);i++){
        if(i==0)a[0]=7%k;
        else a[i]=(10*a[i-1]+7)%k;
        if(a[i]==0){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}
