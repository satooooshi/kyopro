#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



// Ai,j; 1 <= i < j <= N; cant sort! ==  combination組み合わせ！！ of Ai, Aj --> xC2

// Ai - Aj が　200の倍数 つまり Ai%200 ==  Aj%200 --> reminder k is x ko --> xC2

// nimus % 200 --> abs(minus)%200で計算

int main(){

    int n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>backet(200,0);// Ai%200 in range of [0,200)

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    /* TLE
    ll cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(v[i]-v[j])%200==0){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    */

    for(int i=0;i<n;i++){
       backet[v[i]%200]++;
    }

    ll cnt=0;
    for(int i=0;i<200;i++){
       cnt+=(backet[i]*(backet[i]-1)/2);
    }
    cout<<cnt<<endl;
    

    return 0;
}