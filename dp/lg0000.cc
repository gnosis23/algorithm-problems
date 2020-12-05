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
#define MAXN 102

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

void dumpArray(ll *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
void solve() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    vector<ll> dp(n);
    vector<ll> sum(n,0);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int pos = -1, neg = -1;
    for(int i = 0; i < n; ++i) {
        if (nums[i] < 0) {
            if (pos == -1) {
                dp[i] = 1;
                sum[i] = nums[i];
            }
            else {
                dp[i] = dp[pos] + 1;
                sum[i] = sum[pos] + nums[i];    
            }
            if (neg == -1 || (dp[neg] < dp[i]) || (nums[neg] < nums[i])) {
                neg = i;
            }
        } 
        else {
            if (neg == -1) {
                dp[i] = 1;
                sum[i] = nums[i];
            }
            else {
                dp[i] = dp[neg] + 1;
                sum[i] = sum[neg] + nums[i];
            }
            if (pos == -1 || (dp[pos] < dp[i]) || (nums[pos] < nums[i])) {
                pos = i;
            }
        }
    }

    int maxIndex = 0;
    ll ans = sum[0];
    for(int i = 1; i < n; ++i) {
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
            ans = sum[i];
        }
        else if (dp[i] == dp[maxIndex] && sum[i] > sum[maxIndex]) {
            maxIndex = i;
            ans = sum[i];
        }
    }
    dumpArray(&dp[0], n);
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
