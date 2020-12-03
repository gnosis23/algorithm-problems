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
#define MAXN 1001

inline void dumpGraph(int graph[][MAXN], int r, int c) {
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

inline void dumpArray(int *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
// UVa 11400
// Lighting System Design
struct Lamp {
    int v, k, c, l;
    friend bool operator<(const Lamp& a, const Lamp& b) {
        return a.v < b.v;
    }
};
Lamp lamps[MAXN];

int main(int argc, char const *argv[])
{
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for(int i = 0; i < n; ++i) {
            cin >> lamps[i].v >> lamps[i].k >> lamps[i].c >> lamps[i].l;
        }
        sort(lamps, lamps + n);
        
        vector<int> dp(n+1, 0);
        vector<int> sumL(n+1, 0);

        for(int i = 1; i <= n; ++i) {
            sumL[i] = sumL[i-1] + lamps[i-1].l;
        }

        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + lamps[i-1].k + ((sumL[i] - sumL[i-1]) * lamps[i-1].c);
            for(int j = 0; j < i; ++j) {
                dp[i] = min(
                    dp[i],
                    dp[j] + lamps[i-1].k + ((sumL[i] - sumL[j]) * lamps[i-1].c)
                );
            }
        }

        // dumpArray(&dp[0], n+1);
        cout << dp[n] << endl;
    }
    return 0;
}
