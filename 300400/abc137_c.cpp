#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// f(a,b,theta):=の時の入る水の容量の最大値
// bs

double PI = acos(-1);  // PI = 3.141593...
int a,b,x;
bool check(long double deg) {
    if(a*a*b>=2*x){
        long double rad=(90-deg)* PI / 180.0; // in radian
        return 1.0*b*b*a*tan(rad) >= 2.0*x;
    }else{
        long double rad=deg* PI / 180.0; // in radian
        return 1.0*(2*a*a*b-a*a*a*tan(rad)) >= 2.0*x;
    }
}

int main() {

    int n;cin>>n;
    map<string,int>m;
    ll res=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        sort(s.begin(),s.end());
        res+=m[s];
        m[s]++;
    }
    cout<<res<<endl;
 
    return 0;
}