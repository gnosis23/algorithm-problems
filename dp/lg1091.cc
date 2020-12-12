/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://www.luogu.com.cn/problem/P1091
 * tag: DP
 **/
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
int d1[MAXN];
int d2[MAXN];
int nums[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] < nums[j]) {
                d1[j] = max(d1[j], d1[i] + 1);
            }
        }
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[i] < nums[j]) {
                d2[j] = max(d2[j], d2[i] + 1);
            }
        }
    }
    int ans = n - 1;
    for(int i = 0; i < n; ++i) {
        ans = min(ans, (n - 1 - d1[i] - d2[i]));
    }
    cout << ans << endl;
    return 0;
}
