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

ll _nCr(ll n, ll r){ 
   if( n<r || n<0 || r<0 ){ return 0; } 
   ll ans=1; if(r>(n-r)){ r=n-r; } 
   for(ll i=1;i<=r;i++){ ans*=(n+1-i); ans/=i; } 
   return ans; 
}

int main(){

    ll a,b,k;cin>>a>>b>>k;

    string res;

    while(1){
        if(a>0&&b>0){
            //cout<<a<<" "<<b<<" "<<_nCr(a-1+b,a-1)<<endl;
            if(_nCr(a-1+b,a-1)>=k){
                res+='a';
                a--;
            }else{
                res+='b';
                k-=_nCr(a-1+b,a-1);
                b--;
            }
        }else{
            while(b){
                res+='b';
                b--;
            }
            while(a){
                res+='a';
                a--;
            }
        }
        //cout<<res<<endl;
        //cout<<a<<" "<<b<<endl;

        if(a==0&&b==0)break;
    }

    cout<<res<<endl;

    return 0;
}

