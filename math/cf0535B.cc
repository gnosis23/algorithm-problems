/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/535/B
 * tag: nCk
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

// C(n, 0) + c(n, 1) + c(n, 2) + ... + c(n, n) = 2^n
int calc(int n) {
    if (n == 0) return 0;
    int x = n;
    int base = 1;
    int ans = 0;
    while (x % 10 != 0) {
        int d = x % 10;
        ans += base;
        if (d == 7) {
            ans += base;
        }
        base <<= 1;
        x /= 10;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;   
    cout << calc(n) << endl;
}