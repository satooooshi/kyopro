#include <bits/stdc++.h>
using namespace std;


int main(){

    vector<char>minc(26,51); // 1 <= Si <= 50

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        int ch[26]{};
        for(int i=0;i<s.length();i++){
            ch[s[i]-'a']++;
        }

        for(char c='a';c<='z';c++){
            if(minc[c-'a']>ch[c-'a']){ // mark the smallest count of character of all strings
                minc[c-'a']=ch[c-'a'];
            }else if(ch[c-'a']==0){
                minc[c-'a']=-1; // character c is not found in Si
            }
        }
        
    }

    string ans;
    for(char c='a';c<='z';c++){
        if(minc[c-'a']>0){
            string t(minc[c-'a'],c);
            ans+=t;
        }
    }
    cout<<ans<<endl;






    return 0;
}
