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

#define MAXN 100010
void dumpGraph(ll graph[][MAXN], int r, int c) {
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
int dp[MAXN];
const int INF = 1e9;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> d1(n);
    vector<int> d2(n);
    vector<int> qq(n+1);
    vector<int> pos(n+1);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &d1[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &d2[i]);
        pos[d2[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        d1[i] = pos[d1[i]];
    }
    fill(dp, dp+n, INF);
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp, dp+n, d1[i]) = d1[i];
    }
    printf("%ld\n", lower_bound(dp, dp+n, INF) - dp);
    return 0;
}