#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){
	
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        double m=0,a=0,sum=0;
        int s[n];
        REP(i,n){
            cin>>s[i];
            sum+=s[i];
        }
        m=sum/n;
        REP(i,n){
            a+=(s[i]-m)*(s[i]-m)/n;
        }
        cout<<std::fixed << std::setprecision(15) <<(double)sqrt(a)<<endl;

        

    }
}