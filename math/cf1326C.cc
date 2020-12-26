/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1326/C
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
#define MODULO 998244353

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    ll cnt = 1;
    int no;
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        cin >> no;
        if (no > n-k) {
            if (prev != -1) {
                cnt = (cnt * (i - prev)) % MODULO;
            }
            sum += no;
            prev = i;
        }
    }
    cout << sum << " " << cnt << endl;
   return 0;
}
