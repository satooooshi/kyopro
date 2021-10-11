#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){

    string num="0000"; 
    string s;cin>>s;
    int len=s.length();
    int off=0;
    if(len==1){
        off=3;
    }else if(len==2){
        off=2;
    }else if(len==3){
        off=1;
    }else{
        off=0;
    }
    for(int i=0;i<len;i++){
        num[i+off]=s[i];
    }

    cout<<num<<endl;

    return 0;
}