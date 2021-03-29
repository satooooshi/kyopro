//A - Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // [left,right]
    int res = 0;
    for (int i = 0; i < N; ++i) { // also incre here
        ll l=i;
        // cout<<"["<<l<<",";
        // same を抜ける
        while (i+1 < N && A[i] == A[i+1]) ++i;

        // up
        if (i+1 < N && A[i] < A[i+1]) {
            while (i+1 < N && A[i] <= A[i+1]) ++i;
        }
        // down
        else if (i+1 < N && A[i] > A[i+1]) {
            while (i+1 < N && A[i] >= A[i+1]) ++i;
        }
        ll r=i;
        //cout<<r<<"]"<<endl;
        ++res;
    }
    cout << res << endl;
}