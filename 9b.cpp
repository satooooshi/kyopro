#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){


while(1){
   string s;
   int m;
   cin>>s;
   if(s=="-")break;
   int len=s.length();
   //cout<<"length()"<<len<<endl;
   string t=s;
   cin>>m;
   for(int i=0;i<m;i++){
       int h;
       cin>>h;
       string t1=t.substr(0,h);//[,)
       string t2=t.substr(h);// to the end
       t=t2+t1;
       //cout<<t<<endl;

       /* BUGGY!!
       string temp=t;
       for(int j=0;j<len;j++){
           t[((len-h)+j)%len]=temp[j];
       }
       */
         
   }
   cout<<t<<endl;
}
    return 0;
}
