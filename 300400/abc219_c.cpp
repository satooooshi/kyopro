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
    string X;
    cin >> X;
    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
        pos[X[i] - 'a'] = i;
    }
    int N;
    cin >> N;
    vector<string> S(N);
    for (string& s : S) {
        cin >> s;
    }
    // left-hand side, rihgt-hand side
    sort(begin(S), end(S), [&](const string& lhs, const string& rhs) {
        // 文字列の比較
        int len = min(lhs.length(), rhs.length());
        for (int i = 0; i < len; ++i) {
            if (lhs[i] != rhs[i]) {
                return pos[lhs[i] - 'a'] < pos[rhs[i] - 'a'];  // this order from left to right
            }
        }
        return lhs.length() < rhs.length();
    });
    for (const string& s : S) {
        cout << s << '\n';
    }
}
/*
int main() {

    map<char,int>m;
    for(int i=0;i<26;i++){
        char c;cin>>c;
        m[c]=i+1;
    }
    int n;cin>>n;
    vector<pair<string,string>>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i].second;

        string snum;
        for(char c:s[i].second){
            snum+=to_string(m[c]);
        }
        //ll lnum=stoll(snum);
        s[i].first=snum;
    }

    //for(auto e:s)cout<<e.first<<", "<<e.second<<endl;       

    sort(s.begin(),s.end());

    for(int i=0;i<n;i++){
        cout<<s[i].second<<endl;
    }

    return 0;
}

*/