#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    n=min(n,8);//256

    for(int one=0;one<(1<<n);one++){
        for(int two=0;two<(1<<n);two++){
            if(one==0||two==0)continue;// 1≤ x,y≤N
            if(one==two)continue;// identical sets
            //cout<<bitset<8>(one)<<" "<<bitset<8>(two)<<endl;
            ll sone=0;
            ll stwo=0;
            vector<int>onei,twoi;
            for(int i=0;i<n;i++){
                if(one&(1<<i)){
                    sone+=a[i];
                    onei.push_back(i);
                }
                if(two&(1<<i)){
                    stwo+=a[i];
                    twoi.push_back(i);
                }
            }
            if( sone%200 == stwo%200 ){
                    cout<<"YES"<<endl;
                    cout<<onei.size()<<" ";
                    for(auto e:onei)cout<<e+1<<" ";
                    cout<<endl;
                    cout<<twoi.size()<<" ";
                    for(auto e:twoi)cout<<e+1<<" ";
                    cout<<endl;
                    return 0;
                }

        }
    }

    cout<<"NO"<<endl;

    return 0;
}