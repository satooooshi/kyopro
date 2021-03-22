// C - pushpush
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll>b(n);
    int o=n/2;
    if(n%2){
        int e=n/2+1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                b[o]=a[i];
                o--;
            }else{
                b[e]=a[i];
                e++;
            }
        }
    }else{ //n%2==0
        int e=n/2-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                b[o]=a[i];
                o++;
            }else{
                b[e]=a[i];
                e--;
            }
        }
    }
    for(auto x:b){
        cout<<x<<" ";
    }
    cout<<endl;



    return 0;
}
