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

    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int j=0,cnt=0;
    ll res=0;
    for(int i=0;i<n;i++){
        if(i==0)continue;
        else if(i==1){res+=a[0];j++;}
        else{
            res+=a[j];
            cnt++;
        }
        if(cnt==2){
            j++;cnt=0;
        }
    }
    cout<<res<<endl;
    return 0;
}
