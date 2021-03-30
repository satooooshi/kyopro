// C. Exam and Wizard
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    priority_queue<ll>q;
    int n;
    cin>>n;
    vector<ll>a,b;
    rep(i,n){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    ll df=0;
    ll cnt=0;
    rep(i,n){
        ll x;
        cin>>x;
        if(x<a[i]){ // sufficient
            q.push(a[i]-x);
        }else if(a[i]<x){ // deficient
            df+=x-a[i];
            cnt++;
        }
    }

    
    while(df>0&&!q.empty()){
        ll x=q.top();
        q.pop();
        cnt++;
        df-=x;
        
    }

    if(df>0)cout<<-1<<endl;
    else cout<<cnt<<endl;

    return 0;
}
