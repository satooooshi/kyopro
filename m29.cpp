#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    string s,t;
    cin>>s>>t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());
    
    if(s<t)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    

    


    return 0;
}