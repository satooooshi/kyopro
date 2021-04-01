// B - Box and Ball
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;



int main(){

    ll n,m;
    cin>>n>>m;
    vector<ll>x,y;
    vector<bool>rv(n,false);// 0-based indexing
    rv[0]=true;
    vector<ll>box(n,1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        x.push_back(a);
        y.push_back(b);
    }

    for(int i=0;i<m;i++){
        if(rv[x[i]])rv[y[i]]=true;
        box[y[i]]++;
        box[x[i]]--;
        if(box[x[i]]==0)rv[x[i]]=false;
        
        //cout<<i<<" th box ";for(auto x:box){cout<<x;}cout<<endl;
        //cout<<i<<" th rv  ";for(auto x:rv){cout<<x;}cout<<endl;
    }

    ll cnt=0;
    for(int i=0;i<n;i++){
        if(rv[i]==true&&box[i]>0)cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}

