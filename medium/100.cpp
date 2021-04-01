// C - /\/\/\/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


// priority_queue<pair<int,int>>q; // {cnt_appear,num}

int main(){

    int n;
    cin>>n;
    map<int,int>me,mo;
    rep(i,n){
       int x;
       cin>>x;
       if(i&1)mo[x]++;
       else me[x]++;
    }

    vector<pair<int,int>>ve,vo;// {cnt_appeared, num}
    for(auto p:me){
        ve.push_back({p.second,p.first});
    }
    for(auto p:mo){
        vo.push_back({p.second,p.first});
    }

    sort(ve.begin(),ve.end(),greater<pair<int,int>>());
    sort(vo.begin(),vo.end(),greater<pair<int,int>>());

    ll res=-1;
    if(ve[0].first==n/2&&vo[0].first==n/2
        && ve[0].second==vo[0].second){ // case3
            res=n/2;
    }else if(ve[0].second!=vo[0].second){ // case 2
        res=n/2-ve[0].first+n/2-vo[0].first;
    }else if(ve[0].second==vo[0].second
              && ve[0].first!=vo[0].first){ 
        if(ve[0].first<vo[0].first){ // ex. 33332 33344
            res=n/2-vo[0].first+n/2-ve[1].first;
        }else{ // ex. 33344 33332 
            res=n/2-vo[1].first+n/2-ve[0].first;
        }
    }else{
        
    }

    cout<<res<<endl;

    
    return 0;
}
