/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
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
bool isSeven(int n) {
    int x = n;
    while (x > 0) {
        int a = x % 10;
        if (a == 7) return true;
        x /= 10;
    }
    x = n;
    while (x > 0) {
        int a = x % 8;
        if (a == 7) return true;
        x /= 8;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (isSeven(i)) sum++;
    }
    cout << n - sum << endl;
    return 0;
}
