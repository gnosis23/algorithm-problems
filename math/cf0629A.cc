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
// caution: overflow
ll nCk(int n, int k) {
    ll s = 1;
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
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
        if (x >= 2) ans += nCk(x, 2);
        
        x = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j][i] == 'C') x++;
        }
        if (x >= 2) ans += nCk(x, 2);
    }
    cout << ans << endl;
    return 0;
}
