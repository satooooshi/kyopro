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
    vector<int>a(n),w(m);
    for(auto &e:a)cin>>e;
    for(auto &e:w)cin>>e;

    sort(a.begin(),a.end());
    sort(w.begin(),w.end());

    // cusum
    vector<int> sl(n/2+1, 0); // s[0] = 0 になる
    for (int i = 0, j=0; i < n/2; ++i, j+=2) 
        sl[i+1] = sl[i] + max(a[j]-a[j+1],a[j+1]-a[j]);
    //for(auto e:sl)cout<<e<<endl;

    vector<int> sr(n/2+1, 0); // s[0] = 0 になる
    for (int i = 0, j=n-1; i < n/2; ++i, j-=2) 
        sr[i+1] = sr[i] + max(a[j]-a[j-1],a[j-1]-a[j]);
    //for(auto e:sr)cout<<e<<endl;

    ll mn=100000000000;
    for(int i=0;i<m;i++){
        auto idx=lower_bound(a.begin(), a.end(), w[i])-a.begin();
        //cout<<"idx"<<idx<<", "<<sl[idx/2]<<endl;

        if(idx%2==0){
            //cout<<sl[idx/2]+abs(w[i]-a[idx])+sr[n/2-idx/2]<<endl;
            mn=min(mn,1ll*sl[idx/2]+abs(w[i]-a[idx])+sr[n/2-idx/2]);
        }else{
            //cout<<sl[idx/2]+abs(a[idx-1]-w[i])+sr[n/2-idx/2]<<endl;
            mn=min(mn,1ll*sl[idx/2]+abs(a[idx-1]-w[i])+sr[n/2-idx/2]);
        } 
    }

    cout<<mn<<endl;

    return 0;
}
