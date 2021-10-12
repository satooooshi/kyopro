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

    int n,k;cin>>n>>k;
    vector<int>a,b;
    a.push_back(0);
    b.push_back(0);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x<0)a.push_back(x);
        else if(x>0) b.push_back(x);
        else k--;// x == 0
    }

    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());

    vector<int>aa,bb;
    for(int i=1;i<a.size();i++){
        aa.push_back(-1*(a[i]-a[i-1]));
    }
    for(int i=1;i<b.size();i++){
        bb.push_back(b[i]-b[i-1]);
    }
    //for(auto e:aa)cout<<e<<endl;
    //for(auto e:bb)cout<<e<<endl;

    vector<int>saa(aa.size()+1,0),sbb(bb.size()+1,0);
    for(int i=0;i<aa.size();i++){
        saa[i+1]=saa[i]+aa[i];
    }
    for(int i=0;i<bb.size();i++){
        sbb[i+1]=sbb[i]+bb[i];
    }
    //for(auto e:saa)cout<<e<<endl;
    //for(auto e:sbb)cout<<e<<endl;

    int res=inf;
    // wangfang bb
    for(int i=0;i<=k;i++){
        if(k-i>=saa.size())continue;
        if(i>=sbb.size())continue;
        res=min(res,2*sbb[i]+saa[k-i]);
        //res=min(res,2*saa[i]+sbb[k-i]);
        //cout<<i<<","<<sbb[i]<<endl;
        //cout<<k-i<<","<<saa[k-i]<<endl<<endl;
    }

    // wangfang aa
    for(int i=0;i<=k;i++){
        if(i>=saa.size())continue;
        if(k-i>=sbb.size())continue;
        res=min(res,2*saa[i]+sbb[k-i]);
    }
    cout<<res<<endl;

    return 0;
}
