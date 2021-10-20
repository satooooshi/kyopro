#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;


int main() {

    int n;cin>>n;
    vector<int>a(n+1),b(n+1); // 1-based
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    // 調和級数的計算量 O(log2N)
    int cnt=0;
    for(int i=n;i>=1;i--){
        if(i==n){
            b[i]=a[i];
            cnt+=(b[i]==1)?1:0;
        }else{
            int sum=0;
            for(int j=2*i;j<=n;j+=i){
                sum+=b[j];
            }
            if(sum%2==0&&a[i]==0||sum%2==1&&a[i]==1){
                b[i]=0;
            }else{
                b[i]=1;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)if(b[i]==1)cout<<i<<" ";
    cout<<endl;
  
return 0;
}