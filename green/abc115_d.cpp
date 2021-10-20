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

ll n,x;
vector<ll>a(n+1),p(n+1);// level [0,n] n+1 levels in total
    
ll rec(ll i, ll j){ // max j is a[n]
            if(i==0){
                if(j<=0)return 0;
                else return 1;
            }
            if(j==1){
                return 0;
            }else if(1<j&&j<2+a[i-1]){
                return rec(i-1, j-1);
            }else if(j==2+a[i-1]){
                return p[i-1]+1;
            }else if(2+a[i-1]<j&&j<3+2*a[i-1]){
                return p[i-1]+1+rec(i-1,j-2-a[i-1]);
            }else if(j>=3+2*a[i-1]){ // ..BBBB
                return 2*p[i-1]+1;
            }
            /*else{
                cout<<"IMPOSSIBLE"<<endl;
                return -1;
            }*/
}



int main(){
    cin>>n>>x; // x is 1-based
    a.resize(n+1);
    p.resize(n+1);
    a[0]=1;// P
    p[0]=1;
    for(ll i=0;i<n;i++){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }

    cout<<rec(n,x)<<endl;
    return 0;
}

