/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1466/problem/E
 * tag: bitmask | math
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <list>
#include <algorithm>
#include <climits>
#include <cassert>
#ifdef XDebug
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100
#define all(A) A.begin(), A.end()

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
#define MOD 1000000007

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> A(n);
        vector<int> bitCount(61, 0);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < n; ++j) {
                bitCount[i] += (A[j] >> i) & 1;
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll sum1 = 0;
            ll sum2 = 0;
            for (int c = 0; c < 60; ++c) {
                if (A[i] & (1LL << c)) {
                    sum1 = (sum1 + (((1LL << c) % MOD) * bitCount[c])) % MOD;
                    sum2 = (sum2 + (((1LL << c) % MOD) * n)) % MOD;
                }
                else {
                    sum2 = (sum2 + (((1LL << c) % MOD) * bitCount[c])) % MOD;
                }
            }
            ans = (ans + sum1 * sum2) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
