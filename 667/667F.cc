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
#include <algorithm>
using namespace std;

typedef long long ll;

// CODE HERE
#define MAXN 72
int dp[MAXN][MAXN][MAXN/2][MAXN];
int nums[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &nums[i][j]);
        }
    }

    // init
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int x = 0; x <= m/2; ++x) {
                for (int y = 0; y < k; ++y) {
                    dp[i][j][x][y] = INT_MIN;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int cnt = 0; cnt <= m/2; ++cnt) {
                for (int rem = 0; rem < k; ++rem) {
                    if (j != m - 1) {
                        dp[i][j+1][cnt][rem] = max(
                            dp[i][j+1][cnt][rem],
                            dp[i][j][cnt][rem]
                        );
                        if ((cnt + 1) <= m/2) {
                            dp[i][j+1][cnt+1][(rem + nums[i][j])%k] = max(
                                dp[i][j+1][cnt+1][(rem + nums[i][j])%k],
                                dp[i][j][cnt][rem] + nums[i][j]
                            );
                        }
                    }
                    else {
                        dp[i+1][0][0][rem] = max(
                            dp[i+1][0][0][rem],
                            dp[i][j][cnt][rem]
                        );
                        if ((cnt + 1) <= m/2) {
                            dp[i+1][0][0][(rem + nums[i][j])%k] = max(
                                dp[i+1][0][0][(rem + nums[i][j])%k],
                                dp[i][j][cnt][rem] + nums[i][j]
                            );
                        }
                    }
                    // if (dp[i][j][cnt][rem] > 0)
                    // printf("x %d y %d cnt %d rem %d = %d\n", i, j, cnt, rem,
                    //     dp[i][j][cnt][rem]);
                }
            }
        }
    }

    printf("%d\n", max(0, dp[n][0][0][0]));
    return 0;
}
