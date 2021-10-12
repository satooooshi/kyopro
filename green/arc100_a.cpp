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

    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &e:a)cin>>e;

    for(int i=0;i<n;i++){
        b[i]=a[i]-(i+1);
    }
    //for(auto e:a)cout<<e<<endl;

    sort(b.begin(),b.end());
    //for(auto e:b)cout<<e<<endl;
    int mid;
    if (n % 2 == 1) mid = b[n / 2];
    else mid = (b[n / 2 - 1] + b[n / 2]) / 2;
    //cout<<endl<<mid<<endl;
    
    ll res=0;
    for(int i=0;i<n;i++){
        res+=abs(b[i]-mid);
    }    

    cout<<res<<endl;


/*
    ll ans=inf;

    int prev=inf;
    for(int b=0;b>=-mx-10;b--){//for(int b=-mx-10;b<=mx+10;b++){
        ll res=0;
        for(int i=0;i<n;i++){
            //cout<<a[i]<<endl;
            res+=abs(a[i]-b-(i+1));
        }
        if(res>prev)break;
        prev=res;
        //cout<<b<<","<<res<<endl;
        ans=min(ans,res);
    }

    prev=inf;
    for(int b=1;b<=mx+10;b++){
        ll res=0;
        for(int i=0;i<n;i++){
            //cout<<a[i]<<endl;
            res+=abs(a[i]-b-(i+1));
        }
        if(res>prev)break;
        prev=res;
        //cout<<b<<","<<res<<endl;
        ans=min(ans,res);
    }

    cout<<ans<<endl;
*/

    
    return 0;
}

