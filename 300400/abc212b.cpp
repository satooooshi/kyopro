#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    string s;cin>>s;

    bool w1=true;
    for(int i=0;i<4;i++){
        //cout<<(s[(i+1)%4]-'0')<<endl;
        if((s[(i+1)%4]-'0')!=(s[i%4]-'0')){
            w1=false;
            break;
        }
    }
    if(w1){
        cout<<"Weak"<<endl;
        return 0;
    }

    bool w2=true;
    for(int i=0;i<3;i++){
        //cout<<((s[(i)%4]-'0')+1)%10<<endl;
        //cout<<((s[(i+1)%4]-'0')+1)%10<<endl;
        if((s[(i+1)%4]-'0')%10!=((s[i%4]-'0')+1)%10){
            w2=false;
            break;
        }
    }
    if(w2){
        cout<<"Weak"<<endl;
        return 0;
    }



    cout<<"Strong"<<endl;

    return 0;
}