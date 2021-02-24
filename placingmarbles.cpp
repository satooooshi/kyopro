#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    char str[3];
    int s[3];
    int cnt=0;
    scanf("%s",str);
    REP(i,3){
        if(str[i]=='1'){
            cnt++;
        }
    }
    cout<<cnt<<endl;


    return 0;
}