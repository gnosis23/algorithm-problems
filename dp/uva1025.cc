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

#define INF 1e9
#define MAXN 201

// CODE HERE
// UVa1025
// A Spy in the Metro
int dp[MAXN][50];
int Time[MAXN];
int Left[MAXN];
int Right[MAXN];
bool hasBus[MAXN][50][2];

inline void dumpGraph(int graph[][50], int r, int c) {
#ifdef XDebug    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if (graph[i][j] == INF) cout << "I" << " ";
            else cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
}

int main(int argc, char const *argv[])
{
    int ncase = 1;
    while (true) {
        int n, t, m1, m2;
        // input
        cin >> n;
        if (n == 0) break;
        cin >> t;
        for(int i = 0; i < n - 1; ++i) {
            cin >> Time[i];
        }
        cin >> m1;
        for(int i = 0; i < m1; ++i) {
            cin >> Left[i];
        }
        cin >> m2;
        for(int i = 0; i < m2; ++i) {
            cin >> Right[i];
        }

        for(int i = 0; i <= t; ++i) {
            for(int j = 0; j < 50; ++j) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;

        // init
        memset(hasBus, false, sizeof(hasBus));
        // has bus
        for(int i = 0; i < m1; ++i) {
            int t1 = Left[i];
            if (t1 <= t) hasBus[t1][0][0] = true;
            for(int j = 0; j < n - 1; ++j) {
                t1 += Time[j];
                if (t1 <= t) hasBus[t1][j+1][0] = true;
            }
        }
        for(int i = 0; i < m2; ++i) {
            int t1 = Right[i];
            if (t1 <= t) hasBus[t1][n-1][1] = true;
            for(int j = 0; j < n - 1; ++j) {
                t1 += Time[n-2-j];
                if (t1 <= t) hasBus[t1][n-2-j][1] = true;
            }
        }

        for(int _time = 0; _time <= t; ++_time) {
            for(int i = 0; i < n; ++i) {
                if (dp[_time][i] == INF) continue;
                // travel to other left station
                if (hasBus[_time][i][0]) {
                    int t1 = _time;
                    for(int j = i+1; j < n; ++j) {
                        t1 += Time[j-1];
                        if (t1 <= t) {
                            dp[t1][j] = min(dp[t1][j], dp[_time][i]);
                        }
                    }
                }
                // travel to other right station
                if (hasBus[_time][i][1]) {
                    int t1 = _time;
                    for(int j = i-1; j >= 0; --j) {
                        t1 += Time[j];
                        if (t1 <= t) {
                            dp[t1][j] = min(dp[t1][j], dp[_time][i]);
                        }
                    }
                }
                // wait
                for(int j = _time + 1; j <= t; ++j) {
                    dp[j][i] = min(dp[j][i], dp[_time][i] + (j - _time));
                }
            }
            // dumpGraph(dp, t+1, 4);
        }

        cout << "Case Number " << ncase++ << ": ";
        if (dp[t][n-1] == INF) {
            cout << "impossible" << endl;
        } else {
            cout << dp[t][n-1] << endl;
        }
    }
    return 0;
}
