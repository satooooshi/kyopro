#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    map<ll,int>m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        m[a]++;
    }
    int cnt=0;
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(iter->second%2){
            cnt++;
 
        }
    }
 
    cout<<cnt<<endl;
    
    return 0;
}