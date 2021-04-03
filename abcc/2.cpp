// C - Comma
#include <bits/stdc++.h>
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
    int x=0;
    for(ll i=1;i<=n;i*=1000){
        if(n<i*1000){
            //cout<<"r:"<<(n-i)*x<<endl;
            cnt+=(n-i)*x;
            break;
        }
        //cout<<"["<<i<<","<<i*1000<<"):"<<x*(i*1000-i)<<" elems"<<endl;
        cnt+=x*(i*1000-i)+1;
        x++;

    }
    cout<<cnt<<endl;




    return 0;
}


