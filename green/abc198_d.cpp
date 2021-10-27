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

    vector<string>s(3);
    vector<char>al;
    for(int i=0;i<3;i++){
        cin>>s[i];
        for(auto c:s[i]){
            al.push_back(c);
        }
    }
    sort(al.begin(), al.end());
    al.erase(unique(al.begin(), al.end()), al.end());

    if(al.size()>10){
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }

    vector<char>a;
    for(int i=0;i<10;i++){
        a.push_back(i+'0');
    }
    //for(auto e:a)cout<<e<<endl;

    do{
        //for(auto c:a)cout<<c;cout<<endl<<endl;
        map<char,char>m;
        vector<string>num(3);
        vector<ll>n(3);
        for(int i=0;i<al.size();i++){
            m[al[i]]=a[i];
        }
        ///for(auto c:al)cout<<m[c];cout<<endl;
        for(int i=0;i<3;i++){
            for(char c:s[i]){
                num[i]+=m[c];
                //cout<<m[c]<<endl;
            }
            if(num[i][0]=='0')break;
            n[i]=stoll(num[i]);
            //cout<<n[i]<<endl;
        }

        // 正の整数, 先頭に余分な 0 をつけないで
        if(n[0]+n[1]==n[2] && num[0][0]!='0' && num[1][0]!='0' && num[2][0]!='0' ){
            for(int i=0;i<3;i++){
                cout<<n[i]<<endl;  
            }
            return 0;
        }

    }while(next_permutation(a.begin(),a.end()));

    cout<<"UNSOLVABLE"<<endl;

    return 0;
}

