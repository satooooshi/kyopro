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

int main(){

    int h,w;cin>>h>>w;
    int n;cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        for(int j=0;j<x;j++){
            a.push_back(i+1);
        }
    }
    //for(auto e:a)cout<<e<<endl;

    for(int i=0;i<h;i++){
        if(i%2==0)
        for(int j=0;j<w;j++){
            cout<<a[i*w+j]<<" ";
        }
        else
        for(int j=0;j<w;j++){
            cout<<a[i*w+w-j-1]<<" ";
        } 
        cout<<endl;
    }
    

}