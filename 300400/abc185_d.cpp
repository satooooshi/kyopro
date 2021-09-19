#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {
    
    int n,m;cin>>n>>m;
    vector<int>blue(m+2);// blue points
    blue[0]=0;//sentinel
    for(int i=1;i<=m;i++){
        cin>>blue[i];
    }
    blue[m+1]=n+1;//sentinel
    sort(blue.begin(),blue.end());
    vector<int>vec;// white intervals
    int mn=inf;
    for(int i=1;i<m+2;i++){
        if(blue[i]-blue[i-1]-1>0){
            vec.push_back(blue[i]-blue[i-1]-1);
            mn=min(mn,blue[i]-blue[i-1]-1);
        }
        
    }
    //for(auto e:vec)cout<<e<<endl;
    //cout<<mn<<endl;
    ll res=0;
    for(auto e:vec){
        //cout<<e/mn<<endl;
        if(e-(e/mn)*mn>0){
            res+=(e/mn+1);
        }else{
            res+=(e/mn);
        }
    }
    cout<<res<<endl;
    
    return 0;
}
