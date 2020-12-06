/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: UVa10003
 * tag: DP
 * 四边形不等式优化
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 52

inline void dumpGraph(int graph[][MAXN], int r, int c) {
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

inline void dumpArray(int *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
int dp[MAXN][MAXN];
int K[MAXN][MAXN];
void solve(int L) {
    int n;
    cin >> n;
    vector<int> cuts(n+2, 0);
    for(int i = 0; i < n; ++i) {
        cin >> cuts[i+1];
    }
    cuts[n+1] = L;
    // dumpArray(&cuts[0], n+2);

    for(int i = 0; i < n+1; ++i) {
        dp[i][i+1] = 0;
        K[i][i+1] = i;
    }
    // 四边形不等式优化
    for(int Len = 2; Len <= (n+1); ++Len) {
        for(int i = 0; i <= (n+1-Len); ++i) {
            dp[i][i+Len] = INF;
            for(int x = K[i][i+Len-1]; x <= K[i+1][i+Len]; x++) {
                if (dp[i][i+Len] > (dp[i][x] + dp[x][i+Len] + (cuts[i+Len] - cuts[i]))) {
                    dp[i][i+Len] = dp[i][x] + dp[x][i+Len] + (cuts[i+Len] - cuts[i]);
                    K[i][i+Len] = x;
                }
            }
        }
    }

    dumpGraph(K, n+2, n+2);

    cout << "The minimum cutting is "<< dp[0][n+1] << "." << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    while (true) {
        cin >> n;
        if (n == 0)break;
        solve(n);
    }
    return 0;
}
