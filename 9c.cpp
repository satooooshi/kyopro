#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n;
    cin>>n;

    int tp=0,hp=0;
    REP(i,n){
        char t[1000],h[1000];
        scanf("%s %s", t,h);
        if(strcmp(t,h)>0){
            tp+=3;
        }else if(strcmp(t,h)<0){
            hp+=3;
        }else{
            tp++;
            hp++;
        }
    }
    cout<<tp<<" "<<hp<<endl;

    return 0;
}
