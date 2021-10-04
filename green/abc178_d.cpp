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


/*
ll rec(int i,int j){
    if(j==0)return 1;

    ll ret=0;
    for(int k=3;k<=j;k++){ // i+1 th sequence number k
        ret+=rec(i+1,j-k); 
    }
    return ret;
}
// TLE ver.
// recDP
// 数え上げDP
//dpi,j:= i ko mite, nokori tukaeru noga j notokino baainokazu
int main(){

    int s;cin>>s;

    cout<<rec(0,s)%1000000007<<endl;
    
    return 0;
}
*/

int main(){

    int s;cin>>s;
    vector<int>a(s+1);
    a[0]=1;
    a[1]=0;
    a[2]=0;
    for(int i=3;i<=s;i++){
        a[i]=a[i-3]+a[i-1];
        a[i]%=1000000007;
    }
    cout<<a[s]<<endl;

    return 0;
}
