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
int G[101][101];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int r, c;
    int n;
    cin >> r >> c;
    int mv = 100;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> G[i][j];
            mv = min(mv, G[i][j]);
        }
    }
    ll sum = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            sum += G[i][j] - mv;
        }
    }
    cout << sum << endl;
    return 0;
}
