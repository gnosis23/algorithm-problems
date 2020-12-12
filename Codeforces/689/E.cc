/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1461/problem/E
 * tag: math brute-force
 **/
#include <iostream>
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
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 1000010

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
bool dup[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases, n;
    memset(dup, 0, sizeof(dup));

    ll start, L, R, t, x, y;
    cin >> start >> L >> R >> t >> x >> y;
    if (x > y) {
        if ((start + y > R) && ((double)(start - L - y)/(x - y) < t)) {
            puts("NO");
        }
        else if ((start + y <= R) && ((double)(start - L)/(x - y) < t)) {
            puts("NO");
        } 
        else {
            puts("YES");
        }
    }
    else {
        ll rest = start;
        while (t > 0) {
            ll cost = (rest - L) / x;
            t -= cost;
            rest = L + (rest - L) % x;
            if (dup[rest - L] || t <= 0) {
                t = 0; break;
            } else {
                dup[rest - L] = true;
                // cout << "dup: " << rest << endl;
                // test
                if (rest + y > R) break;
                rest += y;
            }
        }
        if (t > 0) {
            puts("NO");
        } else {
            puts("YES");
        }
    }

    
    return 0;
}
