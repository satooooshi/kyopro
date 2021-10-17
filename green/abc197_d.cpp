#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; 
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

double PI = acos(-1);  // PI = 3.141593... in rad

int main() {
    int n;cin>>n;
    double a,b,c,d;cin>>a>>b>>c>>d;
    double r = sqrt((a-c)*(a-c)+(b-d)*(b-d))/2.0;
    double cx = (a+c)/2;
    double cy = (b+d)/2;
    a-=cx;
    b-=cy;
    double rad = atan2(b,a);// in rad // atan2(b,a)*180.0/PI; in deg
    rad+=2.0*PI/n;
    //cout<<rad<<endl;
    double x = r*cos(rad)+cx;
    double y = r*sin(rad)+cy;
    cout << fixed << setprecision(11);
    cout<<x<<" "<<y<<endl;
    return 0;
}