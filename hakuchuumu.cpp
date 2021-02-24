#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){

    string s;
    cin>>s;
    reverse(s.begin(),s.end());

    string str[]={"dream", "dreamer", "erase", "eraser"};
    for(int i=0;i<4;i++){
        reverse(str[i].begin(), str[i].end());
    }

    

    
        for(int j=0;j<s.length();){
            bool ok=false;
            for(int i=0;i<4;i++){
                string d=str[i];
                if(s.substr(j,d.size())==d){
                    j+=d.size();
                    ok=true;
                    break;
                }
            }   
            if(!ok){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    

    cout<<"YES"<<endl;
    return 0;
}
