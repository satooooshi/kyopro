#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int n;
vector<int>a;
vector<int>cnt(10,0);//K=0,1,…,9

void rec(int i, int j){
    if(i==n-1){
        cnt[j]++;
        return ;
    }

    rec( i+1, (a[i+1]+j)%10 );
    rec( i+1, (a[i+1]*j)%10 );

    return ;
}

int main() {

    cin>>n;
    a.resize(n);
    for(auto &e:a)cin>>e;

    // red(i,j):= (先頭 op a[i])%10==jし終わった時のi,j, recDP
    rec(0,a[0]);

    for(int i=0;i<10;i++){
        cout<<cnt[i]<<endl;
    }

    return 0;
}
