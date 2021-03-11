#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    string s;
    cin>>s;
    int n=s.length();

    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
            if(s[j]=='A'||s[j]=='T'||s[j]=='C'||s[j]=='G')cnt++;
            else break;
        }
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;


    return 0;
}