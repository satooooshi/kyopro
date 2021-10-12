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

vector<int>memo;

int rec(int x){
    if(x==0)return 0;
    if(memo[x]!=-1)return memo[x];

    int res=inf;

    res=min(res,rec(x-1)+1);

    for(int i=6;i<=x;i*=6){
        res=min(res,rec(x-i)+1);
    }

    for(int i=9;i<=x;i*=9){
        res=min(res,rec(x-i)+1);
    }

    return memo[x]=res;
}

int main(){

    int n;cin>>n;
    memo.assign(n+1,-1);
    cout<<rec(n)<<endl;

    /* this is not appriable!!
    a.push_back(1);
    for(int i=6;i<=100000;i*=6){
        a.push_back(i);
    }
    for(int i=9;i<=100000;i*=9){
        a.push_back(i);
    }

    sort(a.begin(), a.end()); 
    a.erase(unique(a.begin(), a.end()), a.end());

    for(auto e:a)cout<<e<<endl;cout<<endl;

    int res=0;
    for(int i=a.size()-1;i>=0;i--){
        while(n/a[i]>0){
            cout<<a[i]<<", "<<n/a[i]<<endl;
            res+=n/a[i];
            n%=a[i];
            
        }
    }
    cout<<res<<endl;
    */
    return 0;
}

