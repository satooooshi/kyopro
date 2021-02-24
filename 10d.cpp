#include <stdio.h>
#include <math.h>
#include <cmath>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){
	int n;
	double x[100] = {0},y[100] = {0},p_1 = 0,p_2 = 0,p_3 = 0,p_infinity = -1;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%lf",&x[i]);
	for(int i = 0; i < n; i++) scanf("%lf",&y[i]);

	for(int i = 0; i < n; i++){
		p_1 += abs(x[i] - y[i]);
		p_2 += (x[i] - y[i])*(x[i] - y[i]);
		p_3 += abs((x[i] - y[i])*(x[i] - y[i])*(x[i] - y[i]));
		p_infinity = (p_infinity >= abs(x[i] - y[i]))? 
            p_infinity:abs(x[i] - y[i]);
 	}
	printf("%.6lf\n",p_1);
	printf("%.6lf\n",sqrt(p_2));//square root
	printf("%.6f\n",cbrt(p_3));//cube root
	printf("%.6lf\n",p_infinity);

}