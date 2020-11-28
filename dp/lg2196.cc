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
#define MAXN 20
int gh[MAXN][MAXN];

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

void dumpArray(int *dp, int r, int c) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<int,int>> outNums;
    vector<int> values(n);
    vector<int> dp(n,0);
    vector<int> backs(n,-1);
    int ans = -1;

    memset(gh, 0 , sizeof(gh));
    for(int i = 0; i < n; ++i) {
        cin >> values[i];
        dp[i] = values[i];
        if (ans == -1 || dp[i] > dp[ans]) {
            ans = i;
        }
    }
    for(int i = 0; i < n; ++i) {
        outNums.push_back({0,i});
    }
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) {
            cin >> gh[i][j];
            outNums[i].first++;
        }
    }
    // dumpGraph(gh, n, n);
    sort(outNums.begin(), outNums.end());

    for(int i = 0; i < n; ++i) {
        int u = outNums[i].second;
        for(int j = 0; j < n; ++j) {
            if (gh[j][u] > 0) {
                if (dp[u] + values[j] > dp[j]) {
                    backs[j] = u;
                }
                dp[j] = max(dp[j], dp[u] + values[j]);
                if (ans == -1 || dp[j] > dp[ans]) {
                    ans = j;
                }
            }
        }
        dumpArray(&dp[0], n, n);
    }

    cout << ans+1;
    int current = ans;
    while (backs[current] != -1) {
        current = backs[current];
        cout << " " << (current+1);
    };
    cout << endl;

    cout << dp[ans] << endl;
    return 0;
}
