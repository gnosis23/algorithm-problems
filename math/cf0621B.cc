/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/621/B
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
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 1000
#define all(A) A.begin(), A.end()

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
// caution: overflow
ll nCk(int n, int k) {
    ll s = 1;
    k = min(k, n-k);
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(2*MAXN + 1, 0);
    vector<int> B(2*MAXN + 1, 0);
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        A[MAXN + y - x]++;
        B[y + x]++;
    }
    ll ans = 0;
    for (int i = 0; i <= 2 * MAXN; ++i) {
        if (A[i] >= 2) ans += nCk(A[i], 2);
        if (B[i] >= 2) ans += nCk(B[i], 2);
    }
    cout << ans << endl;
    return 0;
}
