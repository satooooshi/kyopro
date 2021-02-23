#include <bits/stdc++.h>
// ABC061_C
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main() {
    // input
   int r,c;
   cin>>r>>c;
   int a[r+1][c+1]={0};//+1 for sum of row, column
   REP(i,r){
       REP(j,c){
           cin>>a[i][j];
       }
   }

   
   REP(i,r){
       int sum=0;
       REP(j,c){
           sum+=a[i][j];
       }
       a[i][c]=sum;
   }

   REP(i,c+1){ // dont forget sum+=a[r][c]
       int sum=0;
       REP(j,r){
           sum+=a[j][i];
       }
       a[r][i]=sum;
   }

   

    REP(i,r+1){
       REP(j,c+1){
           cout<<a[i][j];
           if(j!=c)cout<<" ";
       }
       cout<<endl;
   }

   





    return 0;
}