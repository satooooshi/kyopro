// B - Choose Integers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int a,b,c;
    cin>>a>>b>>c;

    // amari ha b ko de junnkann
    for(int i=1;i<=b;i++){
        if(a*i%b==c){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;


    return 0;
}
