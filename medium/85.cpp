// A - Diverse Word
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod=1000000000+7;


int main(){

    string s;
    cin>>s;
    int n=s.length();
    map<char,int>m;
    vector<bool>used(26);

    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    //cout<<"m.size():"<<m.size()<<endl;
    int p=-1;
    char newc='A';
    if(m.size()==26){
        for(int i=0;i<n;i++){
            used[s[i]-'a']=true;
            for(char c=s[i]+1;c<='z';c++){
                if(!used[c-'a']){
                    p=i; 
                    newc=c;
                    break; // alphabetically first unused char
                    //cout<<"replacing at S"<<p<<":"<<s[p]<<" with newc:"<<newc<<endl;
                }
            }
        }
        if(p==-1){
            cout<<-1<<endl;
            return 0;
        }
        //cout<<"Finally, replacing S"<<p<<":"<<s[p]<<" with "<<newc<<endl;
        s[p]=newc;
        s=s.substr(0,p+1);
        cout<<s<<endl;
    }else{
        for(int i=0;i<n;i++){
            used[s[i]-'a']=true;
        }
        char ch='A';
        for(int i=0;i<26;i++){
            if(used[i]==false){
                ch='a'+i;
                break;
            }
        }
        s+=ch;
        cout<<s<<endl;
    }


    return 0;
}
