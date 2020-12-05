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
#define MAXN 2001

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
char graph[MAXN][MAXN];
int dp[10];

inline int solve(int n, PII &a, PII &b) {
        int ans = 0;
        ans = max(ans, max(n - a.second - 1, a.second) * (abs(a.first - b.first)));
        ans = max(ans, max(n - b.second - 1, b.second) * (abs(a.first - b.first)));
        ans = max(ans, max(n - a.first - 1, a.first) * (abs(a.second - b.second)));
        ans = max(ans, max(n - b.first - 1, b.first) * (abs(a.second - b.second)));
        return ans;
}

int main(int argc, char const *argv[])
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", graph[i]);
        }
        memset(dp, 0, sizeof(dp));
        vector<PII> points[10];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                points[graph[i][j] - '0'].push_back({i, j});
            }
        }
        for(int i = 0; i <= 9; ++i) {
            int Size = points[i].size();
            if (Size <= 1) continue; 
            sort(points[i].begin(), points[i].end());
            for(int j = 1; j < Size; ++j) {
                dp[i] = max(dp[i], solve(n, points[i][0], points[i][j]));
            }
            for(int j = 0; j < Size-1; ++j) {
                dp[i] = max(dp[i], solve(n, points[i][Size-1], points[i][j]));
            }
            sort(points[i].begin(), points[i].end(), [](PII &a, PII &b) {
                if (a.second == b.second) {
                    return a.first < b.first;
                } else {
                    return a.second < b.second;
                }
            });
            for(int j = 1; j < Size; ++j) {
                dp[i] = max(dp[i], solve(n, points[i][0], points[i][j]));
            }
            for(int j = 0; j < Size-1; ++j) {
                dp[i] = max(dp[i], solve(n, points[i][Size-1], points[i][j]));
            }
        }
        for(int i = 0; i <= 9; ++i) {
            printf("%d", dp[i]);
            if (i != 9) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
