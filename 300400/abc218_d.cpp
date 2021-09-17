#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<pair<int,int>> v(n);// (x,y)
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            if(v[i].first < v[j].first 
                && v[i].second < v[j].second) { // vi lower left, vj upper right
                    if(binary_search(v.begin(), v.end(), make_pair(v[i].first, v[j].second)) 
                        && binary_search(v.begin(), v.end(), make_pair(v[j].first, v[i].second))) {
                            ans++;
                    }
            }
    cout << ans << endl;
}