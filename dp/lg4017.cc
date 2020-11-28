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

#define MAXN 5000
void dumpGraph(int graph[][MAXN], int r, int c) {
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

void dumpArray(int *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
// 食物链的个数

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n);
    vector<int> dp(n, 0);
    vector<int> outNums(n, 0);
    vector<int> inNums(n, 0);
    deque<int> que;

    int a, b;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        outNums[b-1]++;
        inNums[a-1]++;
    }
    for(int i = 0; i < n; ++i) {
        if (outNums[i] == 0) {
            dp[i] = 1;
            que.push_back(i);
        }
    }

    while(!que.empty()) {
        int top = que.front();
        que.pop_front();
        int u = top;
        // cout << "c: " << u+1 << endl;
        for (auto &v : graph[u]) {
            dp[v] = (dp[v] + dp[u]) % 80112002;
            outNums[v]--;
            if (outNums[v] == 0) {
                que.push_back(v);
            }
        }
        // dumpArray(&dp[0], n);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (inNums[i] == 0) ans = (ans + dp[i]) % 80112002;
    }
    cout << ans << endl;
    return 0;
}
