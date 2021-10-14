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

    string n;cin>>n;

    int res=-1;
    for(ll bit=0;bit<(1<<n.length());bit++){ // bit set means that bit digit is used
        if(bit==0)continue;// remove all digits
        int sum=0;
        int cnt=0;
        for(int i=0;i<n.length();i++){
            if(bit&(1<<i)){
                sum+=(n[i]-'0');
                cnt++;
            }
        }
        if(sum%3==0)res=max(res,cnt);
    }

    if(res==-1)cout<<-1<<endl;// impossible
    else cout<<n.length()-res<<endl;



    return 0;
}
