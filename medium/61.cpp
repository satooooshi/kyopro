// D - String Formation
#include <bits/stdc++.h>
// c++などで普通の文字列型の先頭に追加する操作は
// 計算量が悪いため、dequeue
#include <deque> 

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string s;
    int n;
    cin>>s>>n;
    deque<char>dq;
    for(int i=0;i<s.length();i++){
        dq.push_back(s[i]);
    }
    int r=0;
    rep(i,n){
        int q;
        cin>>q;
        if(q==1)r=1-r;
        else if(q==2){
            int f;
            char c;
            cin>>f>>c;
            if(r)f=3-f;
            if(f==1)dq.push_front(c);
            else dq.push_back(c);
        }
        //cout<<s<<endl;
    }
    /*
    if(r){
        for(int i=dq.size()-1;i>=0;i--)cout<<dq[i];
    }else{
        for(int i=0;i<dq.size();i++)cout<<dq[i];
    }
    cout<<endl;
    */
    //
    if (r) reverse(dq.begin(), dq.end());
    for (auto c : dq) cout << c;
    cout<<endl;



    return 0;
}