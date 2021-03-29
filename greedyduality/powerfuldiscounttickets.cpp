// D - Powerful Discount Tickets 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,m;
    cin>>n>>m;
    priority_queue<ll>q;
    rep(i,n){
        ll a;
        cin>>a;
        q.push(a);
    }

    while(!q.empty()&&m){
        ll x=q.top();q.pop();
        x/=2;
        m--;
        if(x!=0){
            q.push(x);
        }
    }

    ll res=0;
    while(!q.empty()){
        ll x=q.top();q.pop();
        res+=x;
    }
    cout<<res<<endl;

    
    


    return 0;
}
