// c bugged
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>a;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    sort(a.begin(),a.end());
    sum=accumulate(a.begin(),a.end(),0);
    if(sum%10==0){
        bool found=false;
        for(auto x:a){
            if(x%10!=0){
                found=true;
                sum-=x;
                break;
            }
        }
        // every elem is divisable by 10
        if(!found){
            cout<<0<<endl;
            return 0;
        }
        
    }

    cout<<sum<<endl;


    return 0;
}