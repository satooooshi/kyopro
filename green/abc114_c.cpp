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


int n;
int len;

int rec(int i,int j, int l){
    if(i>=l){
        if(j<=n){
            map<char,int>m;
            string num=to_string(j);
            for(int i=0;i<num.length();i++){
                m[num[i]]++;
            }
            if(m['3']>0&&m['5']>0&&m['7']>0){
               //cout<<j<<endl; 
               return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }
    int res=0;
    for(int d=3;d<=7;d+=2){
        res+=rec(i+1,j*10+d,l);
    }
    return res;
}


int main(){

    cin>>n;
    len=to_string(n).length();
    // kazoeage rec dp
    int ans=0;
    for(int i=3;i<=len;i++){
        ans+=rec(0,0,i);
    }
    cout<<ans<<endl;
    return 0;
}

