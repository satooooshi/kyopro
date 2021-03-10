#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin>>s;
    ll n=s.length();
    vector<int>a(n,0);
    ll i=0,left=0,right=0,mid=0;
    while(i<n){
        left=i;
        while(s[i]=='R')i++;
        mid=i;
        while(s[i]=='L')i++;
        right=(i-1);
        
        ll ca=mid-left; //#Rs
        ll cb=right-mid+1; //#Ls

        a[mid-1]=(ca+1)/2+cb/2;
        a[mid]=ca/2+(cb+1)/2;

    }

    cout<<a[0];
    for(int i=1;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<endl;

    return 0;
}

