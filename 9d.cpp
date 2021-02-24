#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){

    string s;
    cin>>s;

    int n;
    cin>>n;

    REP(i,n){
        char op[10];
        int a,b;
        
        scanf("%s %d %d",op,&a,&b);
        if(!strcmp(op,"replace")){
            char str[1001];
            scanf("%s",str);
            s=s.replace(a,b-a+1,str);
        }else if(!strcmp(op,"reverse")){
            int left = a,right = b;
	        while(left < right){
		        swap(s[left++],s[right--]);
	        }
        }else{
            cout<<s.substr(a,b-a+1)<<endl;
        }

    }


    return 0;
}

