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

    string s;cin>>s;
    int k;cin>>k;
    vector<string>str;

    for(int i=0;i<s.length();i++){
        // k<=5
        for(int len=0;len<=5;len++){//for(int len=0;len<s.length()-i+1;len++){
            string t=s.substr(i,len);
            str.push_back(t);
        }
    }

    sort(str.begin(),str.end());
    str.erase(unique(str.begin(), str.end()), str.end());

    //for(auto e:str)cout<<e<<endl;

    cout<<str[k]<<endl;
    return 0;
}

