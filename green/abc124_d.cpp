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

vector<pair<char, int>> runLengthEncoding(string s) {
	int n = s.length();
 
	vector<pair<char, int>> res;
	char pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}
 
	res.push_back({ pre, cnt });
	return res;
}

int main() {

    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<pair<char, int>>p=runLengthEncoding(s);
    //for(auto e:p)cout<<e.first<<", "<<e.second<<endl;

    int res=-1;
    int zero=0;
    int cnt=0;
    int l=0;
    // sharitori hou
    for(int r=0;r<p.size();r++){
        cnt += p[r].second;
		if (p[r].first == '0') zero++;
 
		while (k < zero) {
		    cnt -= p[l].second;
			if (p[l].first == '0') zero--;
			l++;
		}
 
		chmax(res, cnt);
	}

    cout<<res<<endl;

    return 0;
}