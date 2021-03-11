#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    string s;
    cin>>n>>s;

    int cnt=0;
    for(int i=2;i<n;i++){
        if(s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='C'){
            cnt++;
        }
    }
    cout<<cnt<<endl;


    return 0;
}