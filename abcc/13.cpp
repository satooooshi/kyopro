// B - Alcoholic
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){
    
    ll n;
    ll x;
    cin>>n>>x;
    vector<int>v(n),p(n);
    ll sum=0.0;
    for(int i=0;i<n;i++){   
        cin>>v[i]>>p[i];
        //cout<<":"<<v[i]*p[i]*0.01<<endl;
        sum+=v[i]*p[i];
        //cout<<"sum:"<<sum<<endl;
        if(sum-x*100>0){
            cout<<i+1<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;

    return 0;
}
