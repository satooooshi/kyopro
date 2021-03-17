// D - 文字列と素数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){

    string s;
    cin>>s;

    vector<char>v={'1','3','5','7','9'};

    map<char,int>m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    if(m.size()>5){
        cout<<-1<<endl;
        return 0;
    }

    do{
        map<char,char>p;
        int i=0;
        for(auto it=m.begin();it!=m.end();it++){
            p[it->first]=v[i];
            i++;
        }
        string x;
        for(char c:s){
            x+=p[c];
        }
        if(is_prime(atol(x.c_str()))){
            cout<<x<<endl;
            return 0;
        }

    }while(next_permutation(v.begin(),v.end()));

    cout<<-1<<endl;

    return 0;
}
