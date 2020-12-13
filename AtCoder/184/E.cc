/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
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
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 2010

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
char G[MAXN][MAXN];
int dp[MAXN][MAXN];
int R, C;
int sx, sy, ex, ey;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        cin >> G[i];
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if (G[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (G[i][j] == 'G') {
                ex = i, ey = j;
            }
        }
    }

    int add;
    while (true)
    {
    }
    
    cout << (dp[ex][ey] == INF ? -1 : dp[ex][ey]) << endl;
    return 0;
}
