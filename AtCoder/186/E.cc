/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag: math
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
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

// 求最小解 ax = b (mod n)
// x, y 可能为负数
ll modeq(ll a, ll b, ll n) {
    ll e, i, d, x, y;
    d = extgcd(a, n, x, y);
    if (b % d > 0) {
        return -1;
    }
    else {
        e = (x * (b / d)) % n;
        // for (int i = 0; i < d; ++i) {
        //   ans = (e + i * (n/d) + n) % n;
        // }
        ll ans = ((e + n) % (n/d)) %n;
        return ans;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int s, k;
        cin >> n >> s >> k;
        cout << modeq(k,n-s,n) << endl;
    }
    return 0;
}
