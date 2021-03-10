#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1000000000+7;

int main(){

    ll n,k;
    cin>>n>>k;

    vector<ll>a(n,0);
    vector<ll>b(2*n,0);

    ll ca=0,cb=0,cc=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=0;i<n;i++){
        b[n+i]=a[i];
    }


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                ca++;
            }
        }
    }

    for(int i=0;i<2*n;i++){
        for(int j=i+1;j<2*n;j++){
            if(b[i]>b[j]){
                cb++;
            }
        }
    }

    ca=ca%mod;
    cb=cb%mod;
    cc=cb-2*ca;
    cc=cc%mod;

    if(k%2==0){
        cout<<(cb*k/2)%mod<<endl;
    }else{
        cout<<(k*ca+(k-1)*cc)%mod<<endl;
    }



    return 0;
}

