/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1433/E
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
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
ll nCk(int n, int k) {
    ll s = 1;
    k = min(k, n-k);
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
    }
    return s;
}

ll nPk(int n, int k) {
    ll s = 1;
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
    }
    return s;
}

ll factorial(int n) {
    ll r = 1;
    for (int i = 1; i <= n; i++) r *= i;
    return r;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    cout << (nCk(n, n / 2) / 2) * factorial(n/2 - 1) * factorial(n / 2 - 1) << endl;
    return 0;
}
