// C - Colorful Leaderboard
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    map<int,int>m;
    int best=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int c=a/400;
        if(c>=8)best++;
        else m[c]++;
    }

    int min=(m.size()==0)?1:m.size();
    // int max=(m.size()>=8)?8:(m.size()+best);
    // besters can pick up any colors listed above
    int max=m.size()+best;
    
    cout<<min<<" "<<max<<endl;

    return 0;
}
