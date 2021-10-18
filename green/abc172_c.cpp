#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main(){

    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;
    vector<ll>sa(n+1,0),sb(m+1,0);
    for(int i=0;i<n;i++){
        sa[i+1]=sa[i]+a[i];
    }
    for(int i=0;i<m;i++){
        sb[i+1]=sb[i]+b[i];
    }

    int res=-1;
    for(int i=0;i<n+1;i++){ //sa[0..n+1)
        if(sa[i]>k)break;
        int rem=k-sa[i];
        if(rem<0)continue;
        int j=upper_bound(all(sb),rem)-sb.begin();
        j--;
        res=max(res,i+j);
        //cout<<i<<" "<<j<<" "<<sa[i]<<endl;
    }
    cout<<res<<endl;
    return 0;
}
