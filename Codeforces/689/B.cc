/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1461/problem/B
 * tag: DP
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

// typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 501

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
char graph[MAXN][MAXN];
int d1[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases, n, m;
    cin >> ncases;
    while (ncases--)
    {
        memset(d1, 0, sizeof(d1));
        int ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            cin >> graph[i];
            for(int j = 0; j < m; ++j) {
                if (graph[i][j] == '*') {
                    ans++;
                    d1[i][j] = 1;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            for(int j = 2; j < m; ++j) {
                if (graph[i][j] != '*') continue;
                int h = d1[i-1][j-1];
                int k = min({h, d1[i][j-1], d1[i][j-2]});
                d1[i][j] = k + 1;
                ans += k;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
