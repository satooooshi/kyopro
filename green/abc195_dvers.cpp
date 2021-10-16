// g++-10 practice2_e.cpp -std=c++17 -I /Users/satoshiaikawa/kyoprodev/ac-lib/ac-library

// -10 for bits/stdc++.h
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const int MOD = 1e9 + 7;

int main() {

    int n,m,q;cin>>n>>m>>q;
    vector<pair<int,int>>vw(n);
    vector<pair<int,int>>x(m);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vw[i].first=b;
        vw[i].second=a;
    }
    for(int i=0;i<m;i++){
        int a;cin>>a;
        x[i].first=a;
        x[i].second=0;
    }
    sort(vw.begin(),vw.end(),greater<pair<int,int>>());

    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;// 0-based
        l--;
        r--;
        vector<pair<int,int>>xx=x;
        for(int i=0;i<m;i++){
            if(l<=i&&i<=r){
                xx[i].second++;
            }
        }

        vector<pair<int,int>>box=xx;
        sort(box.begin(),box.end());
        ll tot=0;
        for(int i=0;i<n;i++){
            //for(int i=0;i<m;i++)cout<<box[i].first<<","<<box[i].second<<" ";cout<<endl;
            for(int j=0;j<m;j++){
                if(box[j].first>=vw[i].second&&box[j].second==0){ // lower_bound, // use box[idx] for vw[i]
                    tot+=vw[i].first;
                    box[j].second++;
                    break; // advance i, searching space for  next vw[i]
                }
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}