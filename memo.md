#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){


    return 0;
}

```cpp
    // c[n][l]={0}; dame!!
    // ll c[i][j]{0}; dame !!
    // ll c[n][l]{};// init with 0
    // std::fill(*c, *c + n*l, 0);
    double x[100] = {0};
    // ==
    double aaa[100]{};
    ll c[n][l]{};// init with 0
    // ==
    REP(i,n){
        REP(j,l){
           c[i][j]=0;
        }
    }

    // allow space, read until \n
    std::getline(std::cin, s);
    cout<<s<<endl;// need endl

    
int calc_digit(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}
int calc_digit(long long N) {
    int res = 0;
    while (N) {
        //cout<<N%10<<endl;
        res+=N%10;
        N /= 10;
        
    }
    return res;
}

    char ch;
	while((ch = getchar()) != EOF){
	}
    string s;
    int nc[26]={};
    while(getline(cin, s)){

    }
```

<Enter><Ctrl-Z><Enter> to generate EOF in visualcode


```cpp  
// cpp での！！！
// string manipulations
// http://farma-11.hatenablog.com/entry/2018/01/18/094729
    string s,p;
    getline(cin, s);
    getline(cin, p);

    s+=s;
    
    if(s.find(p)!=string::npos){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
//\\\\\\\\\\\\\\\\\\\\\\\\
    char ch;
    int a[256]{};
	while((ch = getchar()) != EOF){
        a[ch]++;
       
	}
     for(int i=97;i<=122;i++)cout<<(char)i<<" : "<<a[i]+a[i-32]<<endl;
    

    int left = a,right = b;
	        while(left < right){// banpei!!
		        swap(s[left++],s[right--]);
	        }

// floating point
int main(){
	double x1,y1,x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	printf("%.8lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    //==
     double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    cout<< std::fixed << std::setprecision(8) <<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;

}
```

