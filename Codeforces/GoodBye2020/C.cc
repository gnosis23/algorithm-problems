/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1466/problem/C
 * tag: greedy | dp
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
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100
#define all(A) A.begin(), A.end()

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

// greedy
/**
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.size();
        ll ans = 0;
        for (int i = 1; i < n; ++i) {
            if (str[i] == str[i-1]) {
                ans++;
                str[i] = '0';
            }
            else if (i >= 2 && str[i] == str[i-2]) {
                ans++;
                str[i] = '0';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/

// dp
int dp[100000][2][2];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.size();

        if (n <= 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0][0] = dp[i][1][0] = dp[i][1][1] = dp[i][0][1] = n;
        }

        if (str[1] == str[0]) {
            dp[1][0][1] = 1;
            dp[1][1][0] = 1;
        }
        else {
            dp[1][0][0] = 0;
        }
        for (int i = 2; i < n; ++i) {
            if ((str[i] != str[i-1]) && (str[i] != str[i-2])) {
                dp[i][0][0] = min(dp[i-1][0][0], dp[i-1][0][1]);
                dp[i][0][1] = min(dp[i-1][1][0], dp[i-1][1][1]);
            }
            else if (str[i] == str[i-1] && str[i] != str[i-2]) {
                dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][0][1]) + 1;
                dp[i][0][1] = min(dp[i-1][1][0], dp[i-1][1][1]);
            }
            else if (str[i] != str[i-1] && str[i] == str[i-2]) {
                dp[i][0][0] = dp[i-1][0][1];
                dp[i][0][1] = dp[i-1][1][1];
                dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][1][1]) + 1;
            }
            else {
                dp[i][0][1] = dp[i-1][1][1];
                dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][1][1]) + 1;
            }
        }

        cout << min({dp[n-1][0][0], dp[n-1][0][1], dp[n-1][1][0], dp[n-1][1][1]}) << endl;
    }
    return 0;
}

