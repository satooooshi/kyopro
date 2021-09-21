#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int n,m;cin>>n>>m;
    vector<int>a(n);
    vector<int>flag(n,-1);
    for(int i=0;i<m;i++){
        int s,c;cin>>s>>c;
        // 0 は 1 桁の整数とする。その他の整数については、先頭に 0 をつけた表記は認めない。
        if(s==1&&c==0&&n!=1){
            cout<<-1<<endl;
            return 0;
        }
        // don t allow identical c with on different ss
        if(flag[s-1]==-1 || c==flag[s-1]){
            a[s-1]=c;
            flag[s-1]=c;  
        }else{
            cout<<-1<<endl;
            return 0;
        }

    }

    // n keta min starts from 1...
    if(a[0]==0&&n!=1){
        a[0]=1;
    }

    
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;

    return 0;
}
