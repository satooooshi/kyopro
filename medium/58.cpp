// A - Kenken Race
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    ll n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    a--;
    b--;
    c--;
    d--;

    if(c==d){
        cout<<"No"<<endl;
        return 0;
    }else if(c<d){ // move b to the d first, (b,d) (a,c) do not have ##
        for(int i=a+1;i<c;i++){
            if(s[i-1]=='#'&&s[i]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        for(int i=b+1;i<d;i++){
            if(s[i-1]=='#'&&s[i]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }else{ // [b-1,d+1] has ... for a to jump over b in this section
        for(int i=a+1;i<c;i++){
            if(s[i-1]=='#'&&s[i]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        for(int i=b+1;i<d;i++){
            if(s[i-1]=='#'&&s[i]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        for(int i=b+1;i<=d+1;i++){
            if(s[i-2]=='.'&&s[i-1]=='.'&&s[i]=='.'){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
        return 0;
    }   


    return 0;
}
