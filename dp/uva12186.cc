/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: UVa12186 Another Crisis
 * tag: DP Tree
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
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
vector<int> sons[MAXN];

int dp(int u, int t) {
    if (sons[u].empty()) return 1;
    int k = sons[u].size();
    vector<int> d;
    for(int i = 0; i < k; ++i) {
        d.push_back(dp(sons[u][i], t));
    }
    sort(d.begin(), d.end());
    int c = (k*t - 1) / 100 + 1;
    int ans = 0;
    for(int i = 0; i < c; ++i) {
        ans += d[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    while (true) {
        int n, t;
        cin >> n >> t;
        if (n == 0 && t == 0) break;
        
        int a;
        for(int i = 0; i <= n; ++i) {
            sons[i].clear();
        }
        for(int i = 0; i < n; ++i) {
            cin >> a;
            sons[a].push_back(i+1);
        }
        cout << dp(0, t) << endl;
    }
    return 0;
}
