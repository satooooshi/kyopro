#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i{},x,c;i<(n);++i){
        cin>>x>>c;
        v[--c].push_back(x);
    }
    ll l{},cl{},r{},cr{};// l,r last pos, cl, cr sum of distance traversed
    ll nl{},ncl{},nr{},ncr{};
    for(int i{};i<n;++i){
        if(v[i].empty()) continue;
        sort(v[i].begin(),v[i].end());
        nl=v[i].front();
        nr=v[i].back();
        ncl=min(abs(l-nr)+nr-nl+cl, abs(r-nr)+nr-nl+cr);
        ncr=min(abs(l-nl)+nr-nl+cl, abs(r-nl)+nr-nl+cr);
        l=nl,r=nr, cl=ncl, cr=ncr;
    }
    // cl leftmost at last, go back to origin abs(l)
    cout<<min(cl+abs(l),cr+abs(r))<<endl;
}