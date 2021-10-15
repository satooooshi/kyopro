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


vector<string> trim(vector<string> s){

    int n=s.size();
    int left=inf,right=-1,tp=inf,btm=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='#'){
                left=min(left,j);
                right=max(right,j);
                tp=min(tp,i);
                btm=max(btm,i);
            }
        }
    }
    //cout<<left<<" "<<right<<" "<<tp<<" "<<btm<<endl;
    vector<string>res(btm-tp+1);
    for(int i=tp;i<=btm;i++){
        for(int j=left;j<=right;j++){
            res[i-tp].push_back(s[i][j]);
        }
    }
    //for(auto e:res)cout<<e<<endl;

    return res;
}

bool isEqual(vector<string>s, vector<string>t){

    if(s.size()!=t.size() || s[0].size()!=t[0].size()){
        return 0;
    }
    int h=s.size();
    int w=s[0].size();
    for (int64_t i = 0; i < h; i++) {
        for (int64_t j = 0;j<w;j++) {
            if(s[i][j]!=t[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

vector<string> rotate(vector<std::string> X) {
  int64_t H = static_cast<int64_t>(X.size());
  int64_t W = static_cast<int64_t>(X.at(0).size());

  vector<string> x(W);
  for (int64_t i = 0; i < W; i++) {
    for (int64_t j = H - 1; j >= 0; j--) {
      x.at(i).push_back(X.at(j).at(i));
    }
  }
  return x;
}


// WA!!
int main() {

    int n;cin>>n;
    vector<string>s(n),t(n);
    for(auto &e:s)cin>>e;
    for(auto &e:t)cin>>e;
    //for(auto e:s)cout<<e<<endl;

    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    s=trim(s);
    t=trim(t);

    for(int i=0;i<4;i++){
        t=rotate(t);
        if(isEqual(s,t)){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
