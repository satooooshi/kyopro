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

ll n,k;
vector<ll>a;

bool check(ll x) {  
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]-x>=0){
            cnt+=a[i]-x+1;
        }
    }
    if(cnt<k)return 1;
    return 0;
}

int main() {
    cin>>n>>k;
    a.resize(n);
    for(auto &e:a)cin>>e;
    sort(a.begin(),a.end(),greater<ll>());

    ll left = 0, right = 2*1000000000+1;
    ll ans=right;
    while ( right - left > 1 ) {
        ll mid = (left + right) / 2;
        if(check(mid)){
            right=mid;
            ans=mid;
        }else{
            left=mid;
        } 
    }
    //cout << ans << endl;
    ll cnt=k;
    ll res=0;
    for(int i=0;i<n;i++){
        if(cnt-(a[i]-ans+1)>0 && (a[i]-ans+1)>0 ){
            res+=(ans+a[i])*(a[i]-ans+1)/2;
            // == res+=a[i]*(a[i]+1)/2-ans*(ans-1)/2;
            cnt-=(a[i]-ans+1);
        }else{
            break;
        }
    }
    res+=cnt*(ans-1);
    cout<<res<<endl;
    return 0;
}