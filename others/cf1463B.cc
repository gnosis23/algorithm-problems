/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1463/B
 * tag: greedy | bitmasks | constructive algorithms
 * 整除太难满足，如果用1把数字隔开来的话是不是简单点...
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
#define all(A) A.begin(), A.end()

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

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
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) sum1 += A[i];
            else sum2 += A[i];
        }
        if (sum1 > sum2) {
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                    cout << 1;
                } else {
                    cout << A[i];
                }
                if (i != n-1) cout << " ";
                else cout << endl;
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if ((i & 1) == 0) {
                    cout << 1;
                } else {
                    cout << A[i];
                }
                if (i != n-1) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}
