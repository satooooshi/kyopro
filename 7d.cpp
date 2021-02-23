#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    int n,m,l;
    cin>>n>>m>>l;
    ll a[n][m],b[m][l],c[n][l]{};// init with 0
    // c[n][l]={0}; dame!!
    //ll c[n][l]{(ll)0};
    // std::fill(*c, *c + n*l, 0);
/*
    REP(i,n){
        REP(j,l){
           c[i][j]=0;
        }
    }
*/
    REP(i,n){
        REP(j,m){
            cin>>a[i][j];
            //cout<<"a:"<<a[i][j]<<" ";
        }
    }

    REP(i,m){
        REP(j,l){
            cin>>b[i][j];
            //cout<<"b:"<<b[i][j]<<" ";
        }
    }

    REP(i,n){
        REP(j,l){
            REP(k,m){
                c[i][j]+=(a[i][k]*b[k][j]);
            }
            //cout<<"cij:"<<c[i][j]<<endl;
        }
    }

    REP(i,n){
        REP(j,l){
            cout<<c[i][j];
            if(j!=(l-1))cout<<" ";
        }
        cout<<endl;
    }




    return 0;
}

/*
3 2 3
1 2
0 3
4 5
1 2 1
0 3 2
*/