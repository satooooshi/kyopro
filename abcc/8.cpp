#include <stdio.h>
#define Yes()       printf("Yes\n")
#define No()        printf("No\n")
typedef long long ll;
int main(){
   ll n,m,t,a[1005]={0},b[1005]={0},tmp,now=0;
   scanf("%lld%lld%lld",&n,&m,&t);
   tmp=n;
   for(int i=0; i<m; i++){
       scanf("%lld%lld",&a[i],&b[i]);

       // 消費
       tmp -= (a[i]-now);
       if( tmp <= 0 ){ No(); return 0; }
       now = a[i];

       // 充電
       tmp += (b[i]-now);
       if( tmp > n ){ tmp = n; }   // フル充電
       now = b[i];
   }
   // 最後のカフェ～帰宅
   tmp -= (t-now);

   if( tmp <= 0 ){ No();  }
   else          { Yes(); } 
   return 0;
}