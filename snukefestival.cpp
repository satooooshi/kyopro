#include <bits/stdc++.h>
// ABC077_C
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1


int main(){

    ll n;
    cin>>n;
    vector<ll>a(n),b(n),c(n);

    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n)cin>>c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll nowb,numa,numc,res=0;
    ll idxa,idxc;

    for (ll i=0;i<n;++i){
        nowb=b[i];
        numa=0;
        numc=0;

        auto itera=lower_bound(a.begin(), a.end(),nowb);
        idxa=distance(a.begin(), itera);
        numa=(itera==a.end())?n:idxa;// mimann no kazu

        auto iterc=upper_bound(c.begin(),c.end(),nowb);
        idxc=distance(c.begin(), iterc);
        numc=(iterc==c.end())?0:n-idxc;
        res+=numa*numc; // yoriue no kazu
    }

    cout<<res<<endl;


    return 0;
}


