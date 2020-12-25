/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: http://codeforces.com/problemset/problem/629/A
 * tag: combinatorics
 **/
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
#ifdef XDebug
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 101

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
// 不能超过20
ll nCk(int n, int k) {
    if (n < k) return 0;
    if (n - k > k) k = n - k;
    ll i, j;
    ll s = 1;
    for (i = 0, j = 1; i < k; ++i) {
        s *= (n-i);
        for (; j <= k && (s % j == 0); ++j) s /= j;
    }
    return s;
}

char A[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 'C') x++;
        }
        if (x >= 2) ans += x * (x - 1) / 2;
        
        x = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j][i] == 'C') x++;
        }
        if (x >= 2) ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
