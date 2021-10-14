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

    int n;cin>>n;
    string s;cin>>s;


    int cnt=0;
    int j=0;
    while(j++<10000){ // N≤100
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')cnt++;
            else cnt--;
            if(cnt<0){
                s='('+s;
                cnt++;
                //cout<<s<<endl;
                break;
            }
        }
    }

    cnt=0;
    for(int i=0;i<s.length();i++){
            if(s[i]=='(')cnt++;
            else cnt--;
    }
    for(int i=0;i<cnt;i++){
        s=s+')';
    }
    cout<<s<<endl;

    return 0;
}