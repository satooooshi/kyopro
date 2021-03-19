// C - Guess The Number
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n,m;
    cin>>n>>m;
    vector<int>s(n,0); // si: i+1 th digit is c
    for(int i=0;i<m;i++){
        int d,c;
        cin>>d>>c;
        // do not allow number with leading zero like 002, 03
        if(n>1&&d==1&&c==0){
            cout<<-1<<endl;
            return 0;
        }
        if(s[d-1]!=0&&s[d-1]!=c){ // si with multiple ci values
            cout<<-1<<endl;
            return 0;
        }else
            s[d-1]=c;// zero based indexing
    }

    
    // 100, 10000003432,...
    if(n>1&&s[0]==0){
        s[0]=1;
    }

    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;

    return 0;
}
