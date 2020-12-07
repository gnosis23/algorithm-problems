/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1453/problem/E
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
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 200000

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
vector<int> nodes[MAXN];
int ans;

int dp(int u, int p) {
    int size = nodes[u].size();
    vector<int> sons;
    for(int i = 0; i < size; ++i) {
        if (nodes[u][i] == p) continue;
        int dist = dp(nodes[u][i], u);
        sons.push_back(dist);
    }

    size  = sons.size();
    if (size == 0) return 1;
    if (size == 1) {
        ans = max(ans, sons[0]);
        return sons[0] + 1;
    }

    sort(sons.begin(), sons.end(), [](int &a, int &b) {
        return a > b;
    });

    int ret;
    if (u != 0) {
        ans = max(ans, sons[0] + 1);
        ret = sons[size-1] + 1;
    }
    else {
        ans = max(ans, sons[1] + 1);
        ans = max(ans, sons[0]);
    }
    // cout << u+1 << "[" << ret.first << "," << ret.second << "]" << endl;
    return ret;
}

void solve() {
    ans = 0;
    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; ++i) {
        nodes[i].clear();
    }
    for(int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }

    dp(0, -1);
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    while (ncases--)
    {
        solve();
    }
    
    return 0;
}