// C - Duodecim Ferra

#include <stdio.h>
typedef long long ll;
ll _nCr(ll n, ll r){ 
   if( n<r || n<0 || r<0 ){ return 0; } 
   ll ans=1; if(r>(n-r)){ r=n-r; } 
   for(ll i=1;i<=r;i++){ ans*=(n+1-i); ans/=i; } 
   return ans; 
}

int main(){
   ll i,n,k=12,ans=0;
   scanf("%lld",&n);
   printf("%lld\n",_nCr(n-1,k-1));
   return 0;
}