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



int main() {

    int h,n;cin>>h>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),[](auto const& lhs, auto const& rhs) {
                                    if (lhs.first*rhs.second!=rhs.first*lhs.second) return lhs.first*rhs.second>=rhs.first*lhs.second;
                                    else if (lhs.first != rhs.first) return lhs.first > rhs.first;
                                    else if (lhs.second != rhs.second) return lhs.second < rhs.second;
                                    else return true;
                                });

    for(auto p:vec){
        cout<<p.first<<" "<<p.second<<endl;
    }

    int cnt=h/vec[0].first;
    h=h-cnt*vec[0].first;
    auto idx=lower_bound();
    return 0;
}
