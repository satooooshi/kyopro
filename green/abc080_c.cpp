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


int main() {

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(10));
    vector<vector<int>>p(n,vector<int>(11));
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>f[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            cin>>p[i][j];
        }
    }

    ll res=-inf;
    for(int bit=0;bit<(1<<10);bit++){ // which day his sister opens her shop
        if(bit==0)continue;//1 つ以上の時間帯で店を営業しなければならないこと

        ll sum=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<10;j++){
                if(bit&(1<<j)){ // shop i open at time j
                        cnt+=f[i][j];
                }
            }
            sum+=p[i][cnt];
        }
        res=max(res,sum);
    }

    cout<<res<<endl;

    return 0;
}