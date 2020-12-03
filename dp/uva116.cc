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
#define MAXN 100


// CODE HERE
// UVa116
// Unidirectional TSP
int graph[MAXN][MAXN];
int    dp[MAXN][MAXN];
int   pre[MAXN][MAXN];

void compare(int value, int pos, int &ans, int &before) {
    if (value < ans) {
        ans = value;
        before = pos;
    }
}

int main(int argc, char const *argv[])
{
    int Row, Column;
    while ((scanf("%d %d", &Row, &Column)) != EOF) {
        for(int i = 0; i < Row; ++i) {
            for(int j = 0; j < Column; ++j) {
                scanf("%d", &graph[i][j]);
                dp[i][j] = INF;
                pre[i][j] = -1;
            }
        }

        for(int i = 0; i < Row; ++i) {
            dp[i][Column-1] = graph[i][Column-1];
        }

        for(int i = Column-2; i >= 0; --i) {
            for(int j = 0; j < Row; ++j) {
                int &before = pre[j][i];
                int &ans = dp[j][i];
                int pre1 = dp[(j-1+Row)%Row][i+1] + graph[j][i];
                int pre2 = dp[(j+Row)%Row][i+1] + graph[j][i];
                int pre3 = dp[(j+1+Row)%Row][i+1] + graph[j][i];
                if (j == 0) {
                    compare(pre2, j, ans, before);
                    compare(pre3, (j+1)%Row, ans, before);
                    compare(pre1, (j-1+Row)%Row, ans, before);
                } else if (j == Row-1) {
                    compare(pre3, (j+1)%Row, ans, before);
                    compare(pre1, (j-1+Row)%Row, ans, before);
                    compare(pre2, j, ans, before);
                } else {
                    compare(pre1, (j-1+Row)%Row, ans, before);
                    compare(pre2, j, ans, before);
                    compare(pre3, (j+1)%Row, ans, before);
                }
            }
        }
        // dumpGraph(dp, Row, Column);

        int minIndex = 0;
        for(int i = 1; i < Row; ++i) {
            if (dp[minIndex][0] > dp[i][0]) {
                minIndex = i;
            }
        }

        int cur = minIndex;
        printf("%d", minIndex+1);
        for(int i = 0; i < Column - 1; ++i) {
            cur = pre[cur][i];
            printf(" %d", cur+1);
        }
        printf("\n");
        printf("%d\n", dp[minIndex][0]);
    }
    return 0;
}
