// B - 3人でカードゲームイージー
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    int na=sa.length();
    int nb=sb.length();
    int nc=sc.length();

    int a=0,b=0,c=0;
    char ct=sa[a];
    a++;
    while(true){
        //cout<<"ct:"<<ct<<endl;
        
        if(ct=='a'){
            // 現在自分のターンである人がカードを1枚も持っていない
            if(a==na){
                cout<<"A"<<endl;
                return 0;
            }
            ct=sa[a];
            a++;
        }else if(ct=='b'){
            if(b==nb){
                cout<<"B"<<endl;
                return 0;
            }
            ct=sb[b];
            b++;
        }else{
            if(c==nc){
                cout<<"C"<<endl;
                return 0;
            }
            ct=sc[c];
            c++;
        }
        
    }


    return 0;
}


