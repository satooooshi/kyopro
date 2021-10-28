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

template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
        //dat.assign(n+1,UNITY_SUM);
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* k-th number (k is 0-indexed) */
    int get(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

// segfal
int main(){
    int n;cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;// login [x,x+y)
        a.push_back({x,1});
        a.push_back({x+y,-1});
    }
    sort(all(a));

    int k=0,prev=0;
    vector<int>ans(n+1);// ちょうど k 人がログインしていた日数
    BIT<long long> bit(1010101010);
    for(int i=0;i<a.size();i++){
        k=bit.sum(a[i].first);
        ans[k]+=a[i].first-prev;
        //cout<<a[i].first<<" "<<k<<" "<<a[i].first-prev<<endl;
        if(a[i].second==1)bit.add(a[i].first,1);
        else bit.add(a[i].first,-1);
        prev=a[i].first;
    }
    
    for(int i=1;i<=n;i++)cout << ans[i]<<" ";cout << endl;
    return 0;
}