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

int main() {
    int n;cin>>n;
    vector<int>a(n);
    map<vector<int>,int>ord;
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    vector<int>p(n),q(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>q[i];
    }


    int i=0;
    do{
        ord[a]=i++;
    }while(next_permutation(a.begin(),a.end()));

    cout<<abs(ord[p]-ord[q])<<endl;
    return 0;
}
