#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main(){


    return 0;
}




```cpp

// ruisekiwa
//-------------------------------------------
int N; cin >> n; // 配列サイズ
vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i]; // a の入力

// 累積和
vector<int> s(n+1, 0); // s[0] = 0 になる
for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];
// print S
for (int i = 0; i < n+1; ++i) cout<<s[i]<<endl;

// Sigma A[a,b] == S[b+1]-S[a]
// Sigma A[left,right) == S[right]-S[left]

// 区間 [left, right) の総和を求める
int left, right;
cin >> left >> right;
cout << s[right] - s[left] << endl;

//--------------------------------------------

    for(char c='a'; c<='z'; c++){
    
    }

    // c[n][l]={0}; dame!!
    // ll c[i][j]{0}; dame !!
    // ll c[n][l]{};// init with 0
    // std::fill(*c, *c + n*l, 0);
    double x[100] = {0};
    // ==
    double aaa[100]{};
    ll c[n][l]{};// init with 0
    // ==
    REP(i,n){
        REP(j,l){
           c[i][j]=0;
        }
    }

    // allow space, read until \n
    std::getline(std::cin, s);
    cout<<s<<endl;// need endl

    
int calc_digit(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}
int calc_digit(long long N) {
    int res = 0;
    while (N) {
        //cout<<N%10<<endl;
        res+=N%10;
        N /= 10;
        
    }
    return res;
}

    char ch;
	while((ch = getchar()) != EOF){
	}
    string s;
    int nc[26]={};
    while(getline(cin, s)){

    }
```

<Enter><Ctrl-Z><Enter> to generate EOF in visualcode


```cpp  
// cpp での！！！
// string manipulations
// http://farma-11.hatenablog.com/entry/2018/01/18/094729
    string s,p;
    getline(cin, s);
    getline(cin, p);

    s+=s;
    
    if(s.find(p)!=string::npos){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
//\\\\\\\\\\\\\\\\\\\\\\\\
    char ch;
    int a[256]{};
	while((ch = getchar()) != EOF){
        a[ch]++;
       
	}
     for(int i=97;i<=122;i++)cout<<(char)i<<" : "<<a[i]+a[i-32]<<endl;
    

    int left = a,right = b;
	        while(left < right){// banpei!!
		        swap(s[left++],s[right--]);
	        }

// floating point
int main(){
	double x1,y1,x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	printf("%.8lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    //==
     double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    cout<< std::fixed << std::setprecision(8) <<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;

}


// grid
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const long long INF = 1LL<<60;
int H, W;
vector<string> fi;

long long solve() {
    vector<vector<long long>> dp(H, vector<long long>(W, INF));
    if(fi[0][0]=='#')dp[0][0]=1;
    else dp[0][0]=0;

    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            for(int i=0;i<2;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if (ny<0 || ny>= H || nx<0 || nx>=W)continue;
                int add = 0;
                if (fi[ny][nx] == '#' && fi[y][x] == '.')add=1;
                chmin(dp[ny][nx], dp[y][x] + add);
            }
        }
    }
    return dp[H-1][W-1];
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for (int i = 0; i < H; ++i) cin >> fi[i];
    cout << solve() << endl;
}
```

