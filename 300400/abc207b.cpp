#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b>=c*d){
        cout << -1 << endl;
    }
    else{
        cout << (a-1)/(c*d-b) + 1 << endl;
    }
}