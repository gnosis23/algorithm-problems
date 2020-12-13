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
#define MAXN 1001

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
int A[MAXN];
int B[MAXN];
int dp[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    for(int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= m; ++i) {
        dp[0][i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = min({
                dp[i-1][j] + 1, 
                dp[i][j-1] + 1, 
                (A[i-1] == B[j-1] ? (dp[i-1][j-1]) : (dp[i-1][j-1] + 1) )
            });
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
