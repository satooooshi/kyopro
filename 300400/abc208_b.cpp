#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int p;
    cin>>p;

    vector<ll>coin(10);
    for(int i=0;i<10;i++){
        if(i==0)coin[i]=1;
        else coin[i]=coin[i-1]*(i+1);
    }
    //for(auto e:coin)cout<<e<<endl;
    
    ll cnt=0;
    while(1){
        auto i=upper_bound(coin.begin(),coin.end(),p)-coin.begin();
        if(i-1>=0){
            i--;
        }
        //cout<<"coin:"<<coin[i]<<", p:";
        while(p>=coin[i]){
            p-=coin[i];
            cnt++;
        }
        //cout<<p<<endl;
        if(p==0)break;
    }

    cout<<cnt<<endl;
 
    return 0;
}
