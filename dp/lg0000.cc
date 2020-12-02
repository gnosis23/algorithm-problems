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

#define INF 1e9
#define MAXN 100001

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
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(m+1, 0);
    vector<int> nums(n);

    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for(int i = 0; i < n; ++i) {
        int w = 1;
        for(int j = m; j >= 0; --j) {
            for (int k = 1; k <= nums[i]; ++k) {
                if (j < k) break;
                dp[j] = (dp[j] + dp[j-k]) % 1000007;
            }
        }
        // dumpArray(&dp[0], m+1);
    }
    

    cout << dp[m] << endl;
    return 0;
}