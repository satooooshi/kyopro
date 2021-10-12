#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    int h,w;cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w,-1));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    /*
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j];
        }cout<<endl;
    }
    */
    vector<pair<int,int>>from,to;
    for(int i=0;i<h;i++){
        if(i-1>=0&&a[i-1][w-1]%2){
            a[i-1][w-1]--;
            a[i][w-1]++;
            from.push_back({i,w});
            to.push_back({i+1,w}); 
        }
        for(int j=1;j<w;j++){
           if(j-1>=0&&a[i][j-1]>0&&a[i][j-1]%2){
                a[i][j]++;
                a[i][j-1]--;
                from.push_back({i+1,j});
                to.push_back({i+1,j+1});                
            }
        }
    }
    /*
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }  
    */
    


    cout<<from.size()<<endl;
    for(int i=0;i<from.size();i++){
        cout<<from[i].first<<" "<<from[i].second<<" "<<to[i].first<<" "<<to[i].second<<endl;
    }

    return 0;
}
