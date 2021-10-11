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
    vector<vector<int>>
        col(h+1),
        row(w+1);

    for(int i=0;i<=h;i++){
        col[i].push_back(0);
        col[i].push_back(w+1);
    }
    for(int j=0;j<=w;j++){
        row[j].push_back(0);
        row[j].push_back(h+1);
    }

    // sentinels
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char c;cin>>c;
            if(c=='#'){
                col[i].push_back(j);
                row[j].push_back(i);
            }
        }
    }

    for(int i=0;i<=h;i++){
        sort(col[i].begin(),col[i].end());
    }
    for(int i=0;i<=w;i++){
        sort(row[i].begin(),row[i].end());
    }
/*
    for(auto vec:col){
        for(auto e:vec){
            cout<<e<<" ";
        }cout<<endl;
    }
*/
    // put lamp on i,j
    int res=-1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            auto yoko=lower_bound(col[i].begin(),col[i].end(),j);
            auto tate=lower_bound(row[j].begin(),row[j].end(),i);
            if(*yoko==j&&*tate==i)continue; // i,j is #
            //cout<<i<<","<<j<<":"<<*(yoko-1)<<","<<*yoko<<","<<*(tate-1)<<","<<*tate<<endl;
            int l=*yoko-j-1;
            int r=j-*(yoko-1)-1;
            int u=i-*(tate-1)-1;
            int b=*(tate)-i-1;
            res=max(res,l+r+u+b+1);
            //cout<<l+r+u+b<<endl;
        }
    }

    cout<<res<<endl;
    return 0;
}