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



vector<string> trim(vector<string> vec){
    int mxc=-1,mnc=inf,mxr=-1,mnr=inf;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[0].size();j++){
            if(vec[i][j]=='#'){
                mxc=max(mxc,j);
                mnc=min(mnc,j);
                mxr=max(mxr,i);
                mnr=min(mnr,i);
            }
        }
    }
    vector<string>res;
    for(int i=mnr;i<=mxr;i++){
        res.push_back(vec[i].substr(mnc,mxc-mnc+1));
    }

    /*
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
    */   
    return res;
}


//---------------------------------------------------------------------------------------------------
std::vector<std::string> rotateClockwise(std::vector<std::string> X) {
  int64_t H = static_cast<int64_t>(X.size());
  int64_t W = static_cast<int64_t>(X.at(0).size());

  std::vector<std::string> x(W);
  for (int64_t i = 0; i < W; i++) {
    for (int64_t j = H - 1; j >= 0; j--) {
      x.at(i).push_back(X.at(j).at(i));
    }
  }
    /*
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[0].size();j++){
            cout<<x[i][j];
        }
        cout<<endl;
    }
    */

  return x;
}
//---------------------------------------------------------------------------------------------------

bool isSame(std::vector<std::string> S, std::vector<std::string> T) {
  if (S.size() == T.size() && S.at(0).size() == T.at(0).size())
  {
    bool ok = true;
    for (size_t i = 0; i < S.size(); i++) {
      for (size_t j = 0; j < S.at(0).size(); j++) {
        if (S.at(i).at(j) != T.at(i).at(j)) ok = false;
      }
    }
    return ok;
  } else {
    return false;
  }
}

int main() {
    int n;cin>>n;
    vector<string>S(n),T(n);//0-indexed
    for(auto &a:S)cin>>a;
    for(auto &a:T)cin>>a;

    // exceptions
    if(n==1){cout<<"Yes"<<endl;return 0;}// # == #


  auto s = trim(S);
  auto t = trim(T);

  bool ok = false;
  if ((s.size() == t.size() && s.at(0).size() == t.at(0).size())
      || (s.size() == t.at(0).size() && s.at(0).size() == t.size()))
  {
    for (int64_t i = 0; i < 4; i++) {
      t = rotateClockwise(t);
      if (isSame(s, t)) ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;

}