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
    map<int,int>m;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        m[a]++;
    }
    int MAX=1010101;
    vector<bool>number(MAX,false); // i is multiples of any other numbers??
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>1){
            number[it->first]=true;
        }
        for(int j=2*it->first;j<MAX;j+=it->first){
            number[j]=true;
        }
    }

    int cnt=0;
    for(auto it=m.begin();it!=m.end();it++){
        if(number[it->first]==false)cnt++;
    }
    cout<<cnt<<endl;
    
    return 0;
}
