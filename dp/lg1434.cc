#include <cstdio>
#include <iostream>
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
#include <tuple>
using namespace std;

typedef long long ll;

// CODE HERE
// 滑雪问题
#define MAXN 100
int nums[MAXN][MAXN];
int dp[MAXN][MAXN];
int directions[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
vector<tuple<int,int,int>> nodes;

int main(int argc, char const *argv[])
{
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> nums[i][j];
            dp[i][j] = 1;
            nodes.push_back({nums[i][j], i, j});
        }
    }
    sort(nodes.begin(), nodes.end());

    int ans = 1;

    for (int i = 0; i < R*C; ++i) {
        for (int k = 0; k < 4; ++k) {
            int a = get<1>(nodes[i]);
            int b = get<2>(nodes[i]);
            int x = a + directions[k][0];
            int y = b + directions[k][1];
            if (x >= 0 && x < R && y >= 0 && y < C && nums[a][b] < nums[x][y]) {
                dp[x][y] = max(dp[x][y], dp[a][b] + 1);
                ans = max(ans, dp[x][y]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
