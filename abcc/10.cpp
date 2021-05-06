// C - ABC Tournament
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    int n;
    cin>>n;
    queue<pair<ll,ll>>q;// {rate,idx}
    vector<ll>v(1<<n);
    for(int i=0;i<(1<<n);i++){
        cin>>v[i];
        q.push({v[i],i+1});// 1 based indexing
    }
/*
    while(!q.empty()){
        ll x=q.front().first;
        ll y=q.front().second;
        q.pop();
        cout<<x<<" "<<y<<endl;
    }
*/
    while(q.size()>2){
        ll x=q.front().first;
        ll xi=q.front().second;
        q.pop();
        ll y=q.front().first;
        ll yi=q.front().second;
        q.pop();
        if(x<y)q.push({y,yi});
        else q.push({x,xi});
        //cout<<q.back().first<<endl;
    }

        ll x=q.front().first;
        ll xi=q.front().second;
        q.pop();
        ll y=q.front().first;
        ll yi=q.front().second;
        q.pop();
        // junyuushou
        if(x>y)cout<<yi<<endl;
        else cout<<xi<<endl;

    return 0;
}