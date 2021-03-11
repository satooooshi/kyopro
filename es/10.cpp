#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>x(n);
    vector<int>y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    vector<int>a;
    for(int i=0;i<n;i++){
        a.push_back(i);
    }
    vector<double>avg;
    do{
        double d=0.0;
        for(int i=1;i<n;i++){
            //cout<<x[a[i]]<<"-"<<x[a[i-1]]<<endl;
            d+=sqrt( (x[a[i]]-x[a[i-1]])*(x[a[i]]-x[a[i-1]])
                        +(y[a[i]]-y[a[i-1]])*(y[a[i]]-y[a[i-1]]) );
        }
        avg.push_back(d);
    }while(next_permutation(a.begin(),a.end()));
    
    cout<< std::fixed << std::setprecision(8)<<accumulate(avg.begin(),avg.end(),0.0)/avg.size()<<endl;


    return 0;
}
