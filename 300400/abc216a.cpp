#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int lim=-1;

    if(s[1]=='.'){
        lim=1;
    }else{
        lim=2;
    }

    int y=s[lim+1]-'0';
    if(y<=2){
        cout<<s.substr(0,lim)+"-"<<endl;
    }else if(y<=6){
        cout<<s.substr(0,lim)<<endl;
    }else{
        cout<<s.substr(0,lim)+"+"<<endl;
    }
    return 0;
}