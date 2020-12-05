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
#define MAXN 200001

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
int nums[MAXN];
ll dp[MAXN];

int main(int argc, char const *argv[])
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        memset(dp, 0, sizeof(dp));
        ll ans = 0;
        for(int i = n-2; i >= 0; --i) {
            dp[i] = (nums[i+1] - nums[i]);
            ans += abs(dp[i]);
        }
        
        ll minAns = ans;
        for(int i = 0; i < n; ++i) {
            if (i == 0) {
                minAns = min(minAns, ans - abs(nums[i]-nums[i+1]));
            }
            else if (i == n-1) {
                minAns = min(minAns, ans - abs(nums[i-1]-nums[i]));
            }
            else {
                minAns = min(minAns, ans - abs(nums[i-1]-nums[i]) - abs(nums[i] - nums[i+1]) + abs(nums[i-1]-nums[i+1]));
            }
        }
        
        printf("%lld\n", minAns);
    }
    return 0;
}
