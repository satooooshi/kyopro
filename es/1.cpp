#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n;
    cin>>n;

    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(j*i==n){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;


    return 0;
}