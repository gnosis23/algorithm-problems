/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1328/B
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
    int n, t, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int p1 = 0, p2 = 0;
        int sum = 0;
        for(int i = 1; i <= n-1; ++i) {
            p1++;
            sum += i;
            if (sum >= k) {
                p2 = n - (k - sum + i);
                break;
            }
        }
        p1 = n - 1 - p1;
        for(int i = 0; i < n; ++i) {
            if (i == p1 || i == p2) {
                cout << "b";
            } else {
                cout << "a";
            }
        }
        cout << endl;
        // cout << sum << " " << p1 << ", " << p2 << endl;
    }
    return 0;
}
