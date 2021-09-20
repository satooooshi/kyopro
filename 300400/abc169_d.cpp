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


// prime_factorize
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    //cout << N << ":";
    vector<ll>vec;
    vec.push_back(1);
    for (auto p : res) {
        ll divisor=1;
        for (int i = 0; i < p.second; ++i){
            //cout << " " << p.first;
            divisor=divisor*p.first;
            vec.push_back(divisor);
            //cout<<divisor<<endl;
        } 
    }
    sort(vec.begin(),vec.end());
    ll ans=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]==1)continue;//ある素数 p と正の整数 e を用いて,z=p^eと表せる
        if(N%vec[i]==0){// N が z で割り切れる
            N/=vec[i]; 
        }else{
            continue;
        }

        //cout<<"/"<<vec[i]<<"=="<<N<<endl;
        if(N<1)break;
        ans++;
    }
    cout<<ans<<endl;

}
