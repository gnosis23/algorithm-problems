/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: http://codeforces.com/problemset/problem/1293/B
 * tag: combinatorics
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
    int n, t;
    double ans = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        ans += ((double)1 / i);
    }
    printf("%.10lf\n", ans);
    return 0;
}
