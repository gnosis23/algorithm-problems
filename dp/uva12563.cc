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
#define MAXN 100

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

void solve() {
    int n, t;
    int sum = 0;
    cin >> n >> t;
    vector<int> length(n);
    for(int i = 0; i < n; ++i) {
        cin >> length[i];
        sum += length[i];
    }

    vector<int> dp(t+1, 0);
    vector<int> Count(t+1,0);

    for(int i = 0; i < n; ++i) {
        for(int j = t; j >= length[i]; --j) {
            if (Count[j - length[i]] + 1 > Count[j]) {
                dp[j] = dp[j - length[i]] + length[i];
                Count[j] = Count[j - length[i]] + 1;
            }
            else if (
                (Count[j - length[i]] + 1) == Count[j] &&
                (dp[j-length[i]] + length[i]) > dp[j]
            ) {
                dp[j] = dp[j - length[i]] + length[i];
            }
        }
    }
    // dumpArray(&dp[0], t+1);
    // dumpArray(&Count[0], t+1);

    cout << Count[t-1] + 1 << " " << dp[t-1] + 678 << endl;
}

int main(int argc, char const *argv[])
{
    int n, no = 1;
    cin >> n;
    while (no <= n) {
        cout << "Case " << no++ << ": ";
        solve();
    }
    return 0;
}
