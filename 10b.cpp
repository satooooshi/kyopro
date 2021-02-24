#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){
	double a,b,c,degree,S;
    double pi = 3.141592653589793238;// M_PI
	scanf("%lf %lf %lf",&a,&b,&degree);
	S = (0.5)*a*b*sin(pi*degree/180);
	c = sqrt(a*a+b*b-2*a*b*cos(M_PI*degree/180));
	printf("%.8lf\n",S);
	printf("%.8lf\n",a+b+c);
	printf("%.8lf\n",2*S/a);
}