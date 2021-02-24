#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int calc_digit(int N) {
    int res = 0;
    while (N) {
        //cout<<N%10<<endl;
        res+=N%10;
        N /= 10;
        
    }
    return res;
}

int main(){

    int n,a,b;
    cin>>n>>a>>b;

    int sum=0;
    for(int i=1;i<=n;i++){
        int r=calc_digit(i);
        if(r>=a&&r<=b){
            //cout<<r<<endl;
            sum+=i;
        }
    }

    cout<<sum<<endl;



    return 0;
}
