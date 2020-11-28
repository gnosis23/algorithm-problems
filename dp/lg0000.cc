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
using namespace std;

typedef long long ll;

#define MAXN 21
void dumpGraph(ll graph[][MAXN], int r, int c) {
#ifdef XDebug    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
}

void dumpArray(int *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
inline bool isValid(int x, int y, int a, int b, int *dx, int *dy) {
    for (int i = 0; i < 9; ++i) {
        if (x == (a + dx[i]) && y == (b + dy[i]))
            return false;
    }
    return true;
}

ll gg[2][MAXN][MAXN];

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int dx[9] = {0,-2,-1,1,2,2,1,-1,-2};
    int dy[9] = {0,1,2,2,1,-1,-2,-2,-1};

    int no = 0;
    int cnt = m+n;
    gg[0][0][0] = 1;
    while (cnt--) {
        no = no^1;
        memset(&gg[no][0][0], 0, sizeof(ll) * MAXN * MAXN);
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                if (isValid(i, j, a, b, dx, dy)) {
                    if(i>=1) gg[no][i][j] += gg[no^1][i-1][j];
                    if(j>=1) gg[no][i][j] += gg[no^1][i][j-1];
                }
            }
        }
        // dumpGraph(gg[no], n+1, m+1);
    }

    cout << gg[no][n][m] << endl;
    return 0;
}
