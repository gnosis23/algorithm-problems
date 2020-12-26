/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1272/C
 * tag:
 */
#include <iostream>
#include <iomanip>
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
#include <cassert>
#ifdef XDebug
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
ll nCk(int n, int k) {
    ll s = 1;
    k = min(k, n-k);
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<int> vis(26, 0);
    string str;
    cin >> str;
    for(int i = 0; i < t; ++i) {
        char ch;
        cin >> ch;
        vis[ch - 'a'] = 1;
    }
    ll ans = 0;
    int L = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (vis[str[i] - 'a']) {
            L++;
        } 
        else {
            if (L > 0) {
                ans += nCk(L + 1, 2);
            }
            L = 0;
        }
    }
    if (L > 0) {
        ans += nCk(L + 1, 2);
    }
    cout << ans << endl;
    return 0;
}
