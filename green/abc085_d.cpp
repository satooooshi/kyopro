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



int main(){

    // 切り刀で最強の攻撃力以上の攻撃力を持つ投げ刀sを
    // その刀以外全て投げる、
    // 最後にその刀を投げる
    int n,h;cin>>n>>h;
    vector<pair<int,int>>a(2*n);
    int amx=-1;
    for(int i=0;i<2*n;i++){
        int x;cin>>x;
        a[i].first=x;
        a[i].second=i%2;// 0a thrash, 1b throw
        if(i%2==0){// a
            amx=max(amx,x);
        }
    }

    sort(a.begin(),a.end());

    int cnt=0;
    for(int i=2*n-1;i>=0;i--){
        if(a[i].second==1&&a[i].first>=amx){// b
            cnt++;
            h-=a[i].first;
        }
        if(h<=0){
            cout<<cnt<<endl;
        return 0;
        }
    }



    if(h%amx>0){
        cout<<cnt+h/amx+1<<endl;
    }else{
        cout<<cnt+h/amx<<endl;
    }

    return 0;
}

/*   WA RE
int n,h;
vector<int>a;
vector<int>memo;

int rec(int i,int j){
    //cout<<i<<","<<j<<endl;
    if(i>=2*n&&j>0)return inf;
    if(j<=0)return 0;
    if(memo[j]!=-1)return memo[j];
    
    int res=inf;
    if(i==0){
        //cout<<"a"<<endl;
        res=min( res, rec(i+1, j-a[i])+1 );//a
        res=min( res, rec(i+2, j-a[i+1])+1 );//b
    }else if( (i-1)%2==0 ){ // a
        //cout<<"a"<<endl;
        res=min( res, rec(i, j-a[i-1])+1 );//a
        res=min( res, rec(i+1, j-a[i])+1 );//b
    }else if( (i-1)%2==1  ){ // b
        res=min( res, rec(i+1, j-a[i])+1 );//a
        res=min( res, rec(i+2, j-a[i+1])+1 );//b
    }

    return memo[j]=res;
}

int main(){
    cin>>n>>h;
    a.resize(2*n);
    memo.assign(h+1,-1);
    for(int i=0;i<2*n;i++){
        int x;cin>>x;
        a[i]=x;
    }
    //for(auto e:a)cout<<e<<endl;

    cout<<rec(0,h)<<endl;

    return 0;
}

*/