#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main() {

    

   int q;cin>>q;
   min_priority_queue<ll> que;

    ll offset=0;
   for(int i=0;i<q;i++){
       int p;cin>>p;
       if(p==1){
           int x;cin>>x;
           que.push(x-offset);

       }else if(p==2){
           int x;cin>>x;
           offset+=x;
       }else{
           cout<<que.top()+offset<<endl;
           que.pop();
       }
   }
    

    return 0;
}