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

int main() {

    ll k;cin>>k;
    queue<ll> que;
    vector<ll>vec;
    for(int i=1;i<=9;i++){
        que.emplace(i);
        vec.push_back(i);
    }
    
    while (que.size() != 0) {     // 幅優先探索
        ll state = que.front();  // 現在の状態
        que.pop();
        for (int d=0;d<=9;d++) {
            ll num=state*10+d;
            
            if(abs(state%10-d)<=1){
                vec.push_back(num);
                que.emplace(num);
                //cout<<num<<endl;
                if(vec.size()>=k){
                    sort(vec.begin(),vec.end());
                    cout<<vec[k-1]<<endl;
                    return 0;
                }
            }
        }
    }
  
    return 0;
}