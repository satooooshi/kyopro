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


    int n,m;cin>>n>>m;
    vector<int>a(n);
    for (auto& e : a) {
        cin>>e;
    }

    vector<int>cnt(10000000);// 0..

    for(int i=0;i<m;i++){
        cnt[a[i]]++;
    }

    // mex of first [0,m)
    int res=inf;
    for(int x=0;x<10000000;x++){
        if(cnt[x]==0){
            res=min(res,x);
            break;
        }
    }
    //cout<<res<<endl;

    // shakutori-hou
    for(int i=m;i<n;i++){
        cnt[a[i]]++;
        cnt[a[i-m]]--;
        if(cnt[a[i-m]]==0){
            res=min(res,a[i-m]);
            
        }
    }

    cout<<res<<endl;

    return 0;
}