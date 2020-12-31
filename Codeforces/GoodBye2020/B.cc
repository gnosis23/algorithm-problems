/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1466/problem/B
 * tag: greedy
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

// greedy
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        ll x = A[0];
        ll ans = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] == x) {
                x++;
                ans++;
            }
            else if (A[i] > x) {
                x = A[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
