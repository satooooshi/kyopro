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

vector<bool>divs(100010,false);

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i),divs[i]=true;
            // 重複しないならば i の相方である N/i も push
            if (N/i != i){
                res.push_back(N/i),divs[N/i]=true;
            } 
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main(){

    int n,m;cin>>n>>m;
    vector<int>a(n);
    vector<bool>muled(100010,false);
    for(auto &e:a)cin>>e;
    for(int i=n-1;i>=0;i--){
        if(divs[a[i]]==false){
            enum_divisors(a[i]);
        }
    }

    //for(int i=0;i<=m;i++){
    //    cout<<divs[i]<<endl;
    //}

    for(int i=2;i<=100010;i++){
        if(divs[i]==true&&muled[i]==false)
        for(int j=i;j<=100010;j+=i){
            divs[j]=true;
            muled[j]=true;
        }
    }

    vector<int>res;
    res.push_back(1);
    //cout<<1<<endl;
    for(int i=2;i<=m;i++){
        if(divs[i]==false){
            //cout<<i<<endl;
            res.push_back(i);
        }
    }
    cout<<res.size()<<endl;
    for(auto e:res)cout<<e<<endl;

    return 0;
}