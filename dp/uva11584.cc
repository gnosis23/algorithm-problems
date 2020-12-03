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
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 1002

inline void dumpGraph(bool graph[][MAXN], int r, int c) {
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
// UVa 11584
// 回文区间
char text[MAXN];
bool isPal[MAXN][MAXN];
int dp[MAXN];

void solve() {
    cin >> text;
    int n = strlen(text);
    // init
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            isPal[i][j] = false;
        }
    }

    // calc isPal
    for(int i = 0; i < n; ++i) {
        isPal[i][i] = true;
        int len = 1;
        while ((i-len >= 0) && (i+len < n) && (text[i-len]==text[i+len])) {
            isPal[i-len][i+len] = true;
            len++;
        }

        len = 1;
        while ((i-len+1 >= 0) && (i+len < n) && (text[i-len+1]==text[i+len])) {
            isPal[i-len+1][i+len] = true;
            len++;
        }
    }

    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i] = dp[i-1] + 1;
        if (isPal[0][i]) dp[i] = 1;
        else {
            for(int j = 1; j < i; ++j) {
                if (isPal[i-j][i]) {
                    dp[i] = min(dp[i], dp[i-j-1] + 1);
                }
            }
        }
    }

    cout << dp[n-1] << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
