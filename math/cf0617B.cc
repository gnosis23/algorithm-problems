/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/617/B
 * tag: binary search, nCk, two pointer
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
    int n, t;
    cin >> n;
    vector<int> A(n);
    int prev = -1;
    ll ans = 1;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] == 1) {
            cnt++;
            if (prev != -1) {
                ans *= (i - prev);
            }
            prev = i;
        }
    }
    if (cnt == 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
