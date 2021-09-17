#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

// void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



int main() {

    vector<string>str;
    map<char,int>m;
    for(int i=0;i<3;i++){
        string s;cin>>s;
        str.push_back(s);
        for(auto c:s){
            m[c]++;
        }
    }

    // exception
    if(m.size()>10){
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }

    map<char, int> ord;// alphabet order (only consider appeared ones), 0-indexed
    int i=0;
    for( auto it = m.begin(); it != m.end() ; ++it ) {
        ord[it->first]=i;
        i++;
        std::cout << it->first<<","<<ord[it->first]<< "\n";
    }

    // give numbers to the aphabets according to alphabetical order
    for(string s:str){
        for(char c:s){
            cout<<ord[c];
        }
        cout<<endl;
    }

    // dfs this number allocation


 
    return 0;
}
