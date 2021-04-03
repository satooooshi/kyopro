// C - Doubled
#include <bits/stdc++.h>
//#include <stdlib.h>//atol
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T& b) { if (a < b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T& b) { if (a > b) { int tmp=a; a=b; b=tmp; return 1; } return 0; }
const ll mod=1000000000+7;

int calc_digitnum(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}

int main(){

    ll n;
    cin>>n;

    int num=calc_digitnum(n);

    ll cnt=0;
    for(ll i=1;i*i<=n;i++){
        char buf[sizeof(long)*8+1];//max # digits 12, 10^12
        //string s=ltoa(i,buf,10);//itoa is not ansi C standard and you should probably avoid it.
        snprintf(buf, sizeof(buf), "%ld", i);
        string s=buf;
        s+=s;
        if(atol(s.c_str())<=n){
            //cout<<s<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;// remove null a,b



    return 0;
}