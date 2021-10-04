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

    ll n, x,m;
    cin>>n>>x>>m;
    vector<int>pos(1000000,-1);
    int pv=-1;
    int pi=-1;
    vector<int>ord;

    // exeption
    if(x==0){
        cout<<0<<endl;
        return 0;
    }


    // mod [0,m) cirtulates from pivot value pv 's position pos[pv]

    for(int i=0;i<m;i++){ 
        //cout<<i+1<<" th pow, "<<x<<endl;
        ord.push_back(x);
        if(pos[x]>=0){
            pv=x;
            pi=i;
            break;
        }else{
            pos[x]=i;
        }  
        x*=x;
        x%=m;
    }
    //cout<<endl;cout<<pv<<" appeared @ "<<pos[pv]<<"&"<<pi<<endl;
    //for(auto e:ord)cout<<e<<" ";cout<<endl;
    int a=pos[pv];
    int b=pi-pos[pv];
    //cout<<"a b "<<a<<" "<<b<<endl;

    // cusum
    vector<ll> sa(a+1, 0); // s[0] = 0 になる
    for (int i = 0; i < a; ++i) sa[i+1] = sa[i] + ord[i];
    // cusum
    vector<ll> sb(b+1, 0); // s[0] = 0 になる
    for (int i = 0; i < b; ++i) sb[i+1] = sb[i] + ord[a+i];

    //cout<<sa[a]<<endl;
    //cout<<sb[b]<<endl;


    ll res=0;
    if(n-a>=0){
        n-=a;
        res+=sa[a];//[0,a)
    }else{
        res+=sa[n];
        n-=a;
    }

    if(n-b>=0){
        res+=(n/b)*sb[b];
        n-=(n/b)*b;
    }
    if(n>0){
        res+=sb[n];//[0,n)
        n-=n;
    }
    cout<<res<<endl;

    return 0;
}
