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


int leftwins(char a, char b){
    // draw
    if (a==b)return -1;
    // a wins
    if(a=='G'&&b=='C')return 1;
    if(a=='C'&&b=='P')return 1;
    if(a=='P'&&b=='G')return 1;
    // a loses
    return 0;
}

int main(){

    int n,m;cin>>n>>m;
    vector<pair<int,int>>cnt(2*n);// 0-based {#wins, i}
    for(int i=0;i<2*n;i++){
        cnt[i].first=0;
        cnt[i].second=i;
    }

    vector<string>a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    //for(auto e:a)cout<<e<<endl;

    for(int j=0;j<m;j++){
        for(int i=0;i<2*n;i+=2){
            int x=cnt[i].second;
            int y=cnt[i+1].second;
            if(leftwins(a[x][j],a[y][j])==1){// x wins
                cnt[i].first++;
            }else if(leftwins(a[x][j],a[y][j])==0){// y wins
                cnt[i+1].first++;
            }   
        }
        sort(cnt.begin(),cnt.end(),[](auto p1, auto p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
    }

    for(auto e:cnt){
        //cout<<e.second+1<<"#wins "<<e.first<<endl;
        cout<<e.second+1<<endl;
    }

    return 0;
}