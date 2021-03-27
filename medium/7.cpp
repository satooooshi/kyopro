// B - Cut and Count
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    for(int p=0;p<n;p++){
        vector<int>ba(26);
        vector<int>bb(26);
        for(int i=0;i<p;i++){
            ba[s[i]-'a']++;
        }
        for(int i=p;i<n;i++){
            bb[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(ba[i]>0&&bb[i]>0){
                cnt++;
                //cout<<"p:"<<p<<", "<<char('a'+i)<<endl;
            }
        }
        res=max(cnt,res);
    }
    cout<<res<<endl;


    return 0;
}
