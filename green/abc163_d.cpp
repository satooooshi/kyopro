#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;


int main() {
ll n,k;cin>>n>>k;
int mod=1000000000+7;
ll ans=0;
for(int i=k;i<=n+1;i++){
    //ll sl=i*(0+i-1)/2;
    //ll sr=i*(n-i+1+n)/2;
    //ans+=(sr-sl+1);
    //cout<<i<<" "<<(sr-sl+1)<<endl;
    // == 
    ans+=(-1ll*i*i%mod+i+n*i%mod+1);
    ans%=mod;
}
cout<<ans<<endl;
  
return 0;
}