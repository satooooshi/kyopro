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

    string s,t;
    cin>>s>>t;

    vector<string>res;
    for(int i=0;i<s.length();i++){
        bool ok=true;
        for(int j=0;j<t.length();j++){
            if(i+j>=s.length()){
                ok=false;
                break;
            }
            if(s[i+j]!='?'&&s[i+j]!=t[j]){
                ok=false;
                break;
            }
        }
        if(ok){
            string str=s;
            str=str.replace(i,t.length(),t);
            replace(str.begin(),str.end(),'?','a');
            //cout<<str<<endl;
            res.push_back(str);
        }
    }

    if(res.size()==0){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }

    sort(res.begin(), res.end());
    cout<<res[0]<<endl;

    return 0;
}

