/*
// without duality
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

    int n;
    cin>>n;
    vector<int>b(n-1);
    vector<int>a(n);
    for(int i=0;i<n-1;i++){
        cin>>b[i];
        a[i+1]=b[i];
    }
    a[0]=a[1];

    // for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;

    for(int i=0;i<n-1;i++){
        if(b[i]<max(a[i],a[i+1])){
            a[i]=b[i];
            //cout<<b[i]<<" < max:"<<max(a[i],a[i+1])<<endl;
        }
    }

    // for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;

    cout<<accumulate(a.begin(),a.end(),0)<<endl;

    




    return 0;
}
*/


// with duality
// B1≥max(A1,A2)B2≥max(A2,A3)B3≥max(A3,A4)
// equals to
// B1≥A1 and B1≥A2B2≥A2 and B2≥A3B3≥A3 and B3≥A4
// equals to
// A1≤B1 A2≤min(B1,B2) A3≤min(B2,B3) A4≤B3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){

    int n;
    cin>>n;
    vector<int>b(n-1);
    vector<int>a(n);
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }

    a[0]=b[0];
    for(int i=1;i<n-1;i++){
        a[i]=min(b[i-1],b[i]);
    }
    a[n-1]=b[n-2];
    cout<<accumulate(a.begin(),a.end(),0)<<endl;


    return 0;
}
