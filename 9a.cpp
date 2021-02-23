#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    string w,t;
    int cnt=0;
    getline(cin, w);
    while(1){
        cin>>t;
        if(t=="END_OF_TEXT")break;
        for(int i=0;i<t.length();i++)t[i]=tolower(t[i]);
        if(t==w)cnt++;
        
    }

    cout<<cnt<<endl;

    return 0;
}
