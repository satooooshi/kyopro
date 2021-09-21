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

    string s;cin>>s;
    int q;cin>>q;
    int flipped=0;
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==1)flipped=(1-flipped);
        else{
            int f;char c;cin>>f>>c;
            if(flipped){
                if(f==1){
                    s=s+c;
                }else{
                    s=c+s;
                }
            }else{
                if(f==1){
                    s=c+s;
                }else{
                    s=s+c;
                }
            }
        }

    }

    if(flipped){
        reverse(s.begin(),s.end());
    }

    cout<<s<<endl;
    return 0;
}
