#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    set<int>set;
    cin>>n;
    REP(i,n){
        int a;
        cin>>a;
        set.insert(a);
    }
    
    cout<<set.size()<<endl;

    return 0;
}