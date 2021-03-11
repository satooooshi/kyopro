#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int calc_digitnum(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}

int main(){ 
    
    ll n;
    cin>>n;

    ll ans=0;
    for(int i=1;i<=n;i++){
        if(calc_digitnum(i)%2!=0){
            ans++;
        }

    }

    cout<<ans<<endl;

    return 0;
}

/*
int main(){

    vector<pair<ll,ll>>v;
    v.push_back({0,0});
    v.push_back({9,9}); //1-9
    v.push_back({99,90});
    v.push_back({999,900});
    v.push_back({9999,9000});
    v.push_back({99999,90000});
    v.push_back({99999,900000});//100000-999999

    ll n;
    cin>>n;

    ll sum=0;
    for(int i=1;i<7;i++){
        if(n<v[i].first){
            sum+=(n-v[i-1].first);
            break;
        }else{
            sum+=v[i].second;
        }
    }

    cout<<sum<<endl;

    return 0;
}
*/

