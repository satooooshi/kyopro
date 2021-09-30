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

    int n;cin>>n;
    vector<int>l(n);
    for(int i=0;i<n;i++){
        cin>>l[i];
    }

    sort(l.begin(),l.end());


    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // the longest one's length is smaller than sum of smaller ones' lengths
            int cnt=lower_bound(l.begin(),l.end(),l[i]+l[j])-l.begin();
            res+=(cnt-2);
        }
    }
    cout<<res<<endl;


    return 0;
}
