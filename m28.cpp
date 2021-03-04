#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    ll n,k;
    cin>>n>>k;
    ll p[n];

    for(ll i=0;i<n;i++){
        cin>>p[i];
    }

// ruisekiwa
//-------------------------------------------
// 累積和
vector<int> s(n+1, 0); // s[0] = 0 になる
for (int i = 0; i < n; ++i){
    s[i+1] = s[i] + p[i];
}
//--------------------------------------------

ll acc=0;
ll maxs=-1;
ll maxa=-1;
for(ll b=k-1;b<n;b++){ // Sigma A[a,b] == S[b+1]-S[a]
    ll a=b-(k-1);
    acc=s[b+1]-s[a];
    cout<<"sb+1:"<<b+1<<", acc:"<<acc<<endl;
    if(maxs<acc){
        maxs=acc;
        maxa=a;
    }

}
cout<< std::fixed << std::setprecision(13)<<(double)(maxs+k)/2.0<<endl;




    return 0;
}
