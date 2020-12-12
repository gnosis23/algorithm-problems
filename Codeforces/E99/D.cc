/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1455/problem/D
 * tag: DP greedy
 **/
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
#ifdef XDebug
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 501

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
int dp[MAXN][MAXN];
int nums[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, x;
        cin >> n >> x;
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        
        for(int i = 0; i <= n; ++i) {
            fill(dp[i], dp[i] + MAXN, INF);
        }

        int ans = INF;
        // current: x
        if (nums[0] > x) {
            dp[0][x] = 1;
        }
        int i;
        for(i = 0; i < n; ++i) {
            int pre = (i == 0) ? 0 : nums[i-1];
            if (nums[i] > x && x >= pre) {
                dp[i][x] = 1;
            }
            if (nums[i] < pre) break;
        }
        if (i == n) ans = 0;
        for(i = 0; i < n; ++i) {
            for(int j = 0; j <= 500; ++j) {
                if (dp[i][j] == INF) continue;
                x = nums[i];
                int k = i + 1;
                for(k = i+1; k < n; ++k) {
                    int pre = (k == i+1) ? j : nums[k-1];
                    if (nums[k] > x && x >= pre) {
                        dp[k][x] = min(dp[k][x], dp[i][j] + 1);
                    }
                    if (nums[k] < pre) break;
                }
                if (k == n) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        // dumpGraph(dp, 5, 6);

        cout << ((ans == INF) ? -1 : ans) << endl;
    }
    return 0;
}
