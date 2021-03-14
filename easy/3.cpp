#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int ca=0,cb=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            
            if((ca+cb)<(a+b)){
                cout<<"Yes"<<endl;
                ca++;
            }else{
                cout<<"No"<<endl;
            }

        }else if(s[i]=='b'){
            if((ca+cb)<(a+b)&&cb<b){
                cout<<"Yes"<<endl;
                cb++;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }


    return 0;
}

