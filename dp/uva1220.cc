/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: UVa1220 Hali-Bula
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
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 201

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
vector<int> sons[MAXN];
int dp[MAXN][2];
int ff[MAXN][2];
char name[110];

int visit(int u, int t) {
    if (dp[u][t]) return dp[u][t];
    int size = sons[u].size();
    int ret = 0;
    if (t == 1) {
        ret = 1;
        // choose sons[0]
        int all1 = 1;
        for (int i = 0; i < size; ++i) {
            int sid = sons[u][i];
            ret += visit(sid, 0);
            if (ff[sid][0] == 0) all1 = 0;
        }
        dp[u][1] = ret;
        ff[u][1] = all1;
    }
    else {
        // choose max(sons[1], sons[0])
        int all1 = 1;
        for (int i = 0; i < size; ++i) {
            int sid = sons[u][i];
            // ret += dp[sid][0];
            // if (ff[sid][0] == 0) all1 = 0;
            if (visit(sid, 0) > visit(sid, 1)) {
                ret += dp[sid][0];
                if (ff[sid][0] == 0) all1 = 0;
            }
            else {
                ret += dp[sid][1];
                if (ff[sid][1] == 0) all1 = 0;
            }
            if (dp[sid][0] == dp[sid][1]) all1 = 0;
        }
        dp[u][0] = ret;
        ff[u][0] = all1;
    }
    return ret;
}

void solve(int n) {
    string a, b;
    map<string, int> ids;
    // clear
    for(int i = 0; i < n; ++i) {
        sons[i].clear();
    }
    memset(dp, 0, sizeof(dp));
    memset(ff, 0, sizeof(ff));
    // input
    int cnt = 0;
    cin >> a;
    ids[a] = cnt++;
    for(int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        if (ids.count(a) == 0) {
            ids[a] = cnt++;
        }
        if (ids.count(b) == 0) {
            ids[b] = cnt++;
        }
        sons[ids[b]].push_back(ids[a]);
    }

    int a1 = visit(0, 0);
    int a2 = visit(0, 1);
    if (a1 == a2) {
        cout << a1 << " No" << endl;
    }
    else if (a1 > a2) {
        cout << a1 << " " << (ff[0][0] == 0 ? "No" : "Yes") << endl;
    } 
    else {
        cout << a2 << " " << (ff[0][1] == 0 ? "No" : "Yes") << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
    return 0;
}
