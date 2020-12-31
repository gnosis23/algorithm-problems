/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
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
int G[100][100];

void solve(int n, vector<ll> &A) {
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                ll x = (A[i] & A[j]) * (A[j] | A[k]);
                bitset<8> bb(x);
                ans = (ans + x) % MOD;
            }
        }
    }
    G[A[0]][A[1]] = ans - A[0] * A[0] - A[1] * A[1];
    cout << A[0] << " " << A[1] << " " << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    // cin >> t;
    // while (t--) {
    //     // cin >> n;
    //     n = 2;
    //     vector<ll> A(n);
    //     // for (int i = 0; i < n; ++i) {
    //         // cin >> A[i];
    //     // }
    //     A[0] = 1;
    //     A[1] = t;
    //     solve(n, A);
    // }
    for (int j = 0; j < 10; ++j) {
    for (int i = 0; i < 10; ++i) {
        n = 2;
        vector<ll> A(n);
        A[0] = j;
        A[1] = i;
        solve(n, A);
    }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%4d ", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
