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


int main(){
    int n;cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;// login [x,x+y)
        a.push_back({x,1});
        a.push_back({x+y,-1});
    }
    sort(all(a));

    int k=0,prev=0;
    vector<int>ans(n+1);// ちょうど k 人がログインしていた日数
    for(int i=0;i+1<a.size();i++){
        k+=a[i].second;
        ans[k]+=a[i+1].first-a[i].first;
    }
    
    for(int i=1;i<=n;i++)cout << ans[i]<<" ";cout << endl;
    return 0;
}