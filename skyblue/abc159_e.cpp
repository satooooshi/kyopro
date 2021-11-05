// 2d cusum
// 値を途中で変更するなどの「更新」があった場合は、累積和を計算し直す必要があるので逆に非効率になります。
// そのような場合は、BIT などのデータ構造を2次元に対応させると
// 更新：𝑂(log𝐻𝑊)
// クエリ：𝑂(log𝐻𝑊)
// で処理ができます。

#include <bits/stdc++.h>
using namespace std;

//#define DEBUG bit==5//b101
#define DEBUG bit==7//b111

typedef long long ll; const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int h,w,k;
vector<vector<int>>s;

// 前処理を行う
void pre_process(vector<vector<int>> const &a, vector<vector<int>> &S) {
    int H = (int)a.size();
    int W = (int)a[0].size();
    S.assign(H + 1, vector<int>(W + 1));
    for (int h = 1; h < H + 1; h++) {
        for (int w = 1; w < W + 1; w++) {
            S[h][w] = a[h - 1][w - 1] + S[h][w - 1] + S[h - 1][w] - S[h - 1][w - 1];
        }
    }
}
// [h1,h2)×[w1,w2) の区間和を求める
int query(int h1, int h2, int w1, int w2, vector<vector<int>> const &S) {
    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];
}
int main() {
    vector<vector<int>> a = {{1, 2, 3, 4},
                             {1, 2, 3, 4},
                             {1, 2, 3, 4},
                             {1, 2, 3, 4}};
    //vector<vector<int>> S;
    //pre_process(a, S);
    //cout << query(1, 3, 2, 3, S) << endl;  // [1,3)×[2,3) = 3+3 = 6
    //cout << query(0, 4, 0, 4, S) << endl;  // [0,4)×[0,4) = 40

    
    cin>>h>>w>>k;
    s.assign(h,vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;cin>>c;
            s[i][j]=c-'0';
        }
    }
    vector<vector<int>>S;
    pre_process(s, S);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << query(0, i+1, 0, j+1, S)<<" ";
        }
        cout<<endl;
    }

    int res=inf;
    for(int bit=0;bit<(1<<h);bit++){// i th bit set equal cut after i th row(0-based)
        if(!bit&(1<<h))continue; // bottom cut and bottom cut dont count as one cut
        if(DEBUG)cout<<bitset<3>(bit)<<endl;
        
        vector<int>yoko;
        int cnt=0;//cut count
        for(int i=0;i<h;i++){
            if(bit&(1<<i)){
                yoko.push_back(i);
                cnt++;
            }
        }

        bool ok=true;
        int lj=-1;
        for(int j=0;j<w;j++){

            int tot=0; // total of [lj,j] across yoko
            int li=-1;
            for(auto e:yoko){
                int i=e;
                if(DEBUG)cout<<"h:["<<li+1<<","<<i+1<<") x "<<"w:["<<lj+1<<" "<<j+1<<")"<<endl;
                if(DEBUG)cout<<S[i+1][j+1]-S[li+1][j+1]-S[i+1][lj+1]+S[li+1][lj+1]<<endl;
                tot+=S[i+1][j+1]-S[li+1][j+1]-S[i+1][lj+1]+S[li+1][lj+1];
                li=e;
            }
            if(tot<=k){
                lj=j;
                if(DEBUG)cout<<"cut@"<<lj<<endl;
            }else{
                if(lj+1>=j){
                    ok=false;
                    break;// cannot fit, try next yoko comb.
                }else{
                    cnt++;//cut at lj
                    
                    continue; // try next j (split chocolate vertically)
                } 
            }

        }
        if(DEBUG)cout<<cnt<<endl;
        if(ok){
            chmin(res,cnt);
        }
        
    }

    cout<<res<<endl;


    return 0;
}