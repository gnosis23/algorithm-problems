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
#define MAXN 1001

inline void dumpGraph(double graph[][MAXN], int r, int c) {
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
// UVa1347
// Tour
double val[MAXN][MAXN];


inline double dist(PII &a, PII &b) {
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double solve(int a, int b, int n, vector<PII> &points) {
    if (val[a][b] > 0) return val[a][b];
    double &ans = val[a][b];
    if (a == n - 1) {
        ans = dist(points[a-1], points[n-1]) + dist(points[b-1], points[n-1]);
    } else {
        ans = solve(a+1, b, n, points) + dist(points[a-1], points[a]);
        ans = min(ans, solve(a+1, a, n, points) + dist(points[a], points[b-1]));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<PII> points;
        memset(val, 0, sizeof(val));

        for(int i = 0; i < n; ++i) {
            int a,  b;
            scanf("%d %d", &a, &b);
            points.push_back({a, b});
        }

        solve(2, 1, n, points);
        // dumpGraph(val, n+1, n+1);
        printf("%.2lf\n", dist(points[0], points[1]) + solve(2, 1, n, points));
    }
    return 0;
}
