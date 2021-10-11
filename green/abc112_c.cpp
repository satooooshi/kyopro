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
    int n;cin>>n;
    vector<int>x(n),y(n),h(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>h[i];
    }

    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
                
                int H=-1;
                // H is manhattan distance of cy cx xi yi hi , 一意に決まる
                for(int i=0;i<n;i++)if(h[i]>0)H=h[i]+abs(x[i]-cx)+abs(y[i]-cy);
                bool ok=true;
                for(int i=0;i<n;i++){
                    if( h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy),0 ) ){
                        ok=false;
                    }
                }
                if(ok){
                    cout<<cx<<" "<<cy<<" "<<H<<endl;
                    //return 0;
                }

        }
    }

}

