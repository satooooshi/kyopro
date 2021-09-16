#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  long long res1=(n*(n-1)/2),res2=0;
  
  map<int,long long> mp;
  for(int i=0;i<n;i++){mp[a[i]]++;}
  for(int i=0;i<n;i++){res2+=(n-mp[a[i]]);}
  res2/=2;
  
  sort(a.begin(),a.end());
  a.push_back(-1);
  long long cnt=1;
  for(int i=0;i<n;i++){
    if(a[i]!=a[i+1]){
      res1-=((cnt*(cnt-1))/2);
      cnt=1;
    }
    else{cnt++;}
  }
  assert(res1==res2);
  cout << res1 << '\n';
  //cout << res2 << '\n';

    return 0;
}