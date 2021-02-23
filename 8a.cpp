#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    string s;
    std::getline(std::cin, s);

    for(int i=0;i<s.length();i++){
        if(isupper(s[i])){
            s[i]=tolower(s[i]);
        }else if(islower(s[i])){
            s[i]=toupper(s[i]);
        }
    }

    cout<<s<<endl;

    return 0;
}