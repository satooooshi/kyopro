#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int a,b;
    cin>>a>>b;
    //a0:1 最初差込口を 1 口
    //a1:a
    //a2:a1+(a-1)
    //a3:a2+(a-1)
    //an:an-1+(a-1)>10 stop
    int s=1;
    int cnt=0;
    while(s<b){
        s=s+(a-1);
        cnt++;
    }

    cout<<cnt<<endl;


    return 0;
}