#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    cout<< std::fixed << std::setprecision(15) <<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;


    return 0;
}
