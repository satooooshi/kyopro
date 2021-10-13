// isprime
// enumerate prime factors(素因数)
// enumerate divisors（約数）
//　
#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> mebius;
    vector<int> min_factor;

    Eratos(int MAX) : primes(),
                      isprime(MAX+1, true),
                      mebius(MAX+1, 1),
                      min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            mebius[i] = -1;
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if ((j / i) % i == 0) mebius[j] = 0;
                else mebius[j] = -mebius[j];
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    // prime factorization
    // 1は素数ではありません, not included in res
    vector<pair<int,int>> prime_factors(int n) {
        vector<pair<int,int> > res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }

    // enumerate divisors
    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = prime_factors(n);
        for (auto p : pf) {
            int n = (int)res.size();
            for (int i = 0; i < n; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

int main() {
    int q;cin>>q;
    const int MAX = 101010;//10^5
    Eratos er(MAX);

    vector<int>s(MAX+1,0);
    for(int i=0;i<MAX;i++){
        if(i%2==1&&er.isprime[i]&&er.isprime[(i+1)/2]){
            s[i+1]=s[i]+1;
        }else{
            s[i+1]=s[i];
        }
        
    }


    vector<int>res;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        res.push_back(s[r+1]-s[l]); // [l,r+1)
    }
    for(auto e:res)cout<<e<<endl;


    //for(int i=0;i<10;i++)cout<<"s"<<i<<","<<s[i]<<endl;


    return 0; 
}


