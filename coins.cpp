#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    //50*50*50: capable of 3 loops
    int a,b,c,x,cnt=0;
    cin>>a>>b>>c>>x;
    
    REP(i,a+1){
        REP(j,b+1){
            REP(k,c+1){
                if(x==(i*500+j*100+k*50))cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
