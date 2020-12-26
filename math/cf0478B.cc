/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/478/B
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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll mx = n - (m - 1);
    ll nMax = mx * (mx - 1) / 2;
    ll base = n / m;
    ll m1 = m - (n % m);
    ll m2 = m - m1;
    ll nMin = base * (base - 1) / 2 * m1 + base * (base + 1) / 2 * m2;
    cout << nMin << " " << nMax << endl;
    return 0;
}
