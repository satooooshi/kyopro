#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(){
    int N;
    cin>>N;
    int h[N];
    for(int i=0;i<N;i++){
        cin>>h[i];
    }

    int c=0;
    while(1){
        int zc=0;
        for(int i=0;i<N;i++){
            if(h[i]<=0) zc++;
            if(h[i]>0&&(i==0||h[i-1]<0)) c++;
            h[i]--;
        }
        if(zc==N) break;
    }
    cout<<c<<endl;
}