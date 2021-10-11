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

long long GCD(long long x, long long y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

map<int,int>m;

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);m[i]++;
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i),m[N/i]++;

        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main(){

    int n;cin>>n;
    vector<int>a(n);
    for(auto &e:a){
        cin>>e;
    }

    vector<int>sl(n,0),sr(n,0);  // slj==max divisor of a[0]..a[j]
    sl[0]=a[0];sr[0]=a[n-1];
    for(int i=1;i<n;i++){
        sl[i]=GCD(sl[i-1],a[i]);
        sr[i]=GCD(sr[i-1],a[n-1-i]);
    }
/*
    for(int i=0;i<n;i++){
        cout<<"sl "<<sl[i]<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<"sr "<<sr[i]<<endl;
    }
*/
    int res=max(sl[n-2],sr[n-2]); // max of a0..n-2 and a1..n-1
    for(int i=0;i<n;i++){
        //cout<<sl[i]<<","<<sr[n-i-3]<<endl;
        res=max(res,(int)GCD(sl[i],sr[n-i-3]));
    }
    cout<<res<<endl;

/* TLE
    for(int i=0;i<n;i++){
        enum_divisors(a[i]);
    }
    for(auto it=m.end();it!=m.begin();it--){
        if(it->second>=n-1){
            cout<<it->first<<endl;
            return 0;
        }
    }
*/

    return 0;
}

