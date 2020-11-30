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
    vector<int> nums;
    int x;
    while((scanf("%d", &x)) != EOF) {
        nums.push_back(x);
    }

    int n = nums.size();
    vector<int> dp(n,INF);
    for(int i = n-1; i >= 0; --i) {
        *upper_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
    }
    printf("%ld\n", lower_bound(dp.begin(), dp.end(), INF) - dp.begin());
    
    fill(dp.begin(), dp.end(), INF);
    for(int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
    }
    printf("%ld\n", lower_bound(dp.begin(), dp.end(), INF) - dp.begin());

    return 0;
}
