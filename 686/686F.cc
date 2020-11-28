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
#include <algorithm>
using namespace std;

typedef long long ll;

// CODE HERE
int nums[200001];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    int maxL = 0;

    for (int i = 0; i <= n - 3; ++i) {
        maxL = max(nums[i], maxL);
        
        int r;
        int maxR = 0;
        for (int j = n - 1; j >= i + 2; --j) {
            if (nums[j] > maxL) {
                break;
            }
            r = j;
            maxR = max(maxR, nums[j]);
        }

        if (maxR != maxL) continue;
        
        // assert(i+1 < r);
        // minM = min[i+1, r-1]
        int minM = INT_MAX;
        for (int j = i + 1; j < r; ++j) {
            minM = min(minM, nums[j]);
        }

        if (minM == maxL) {
            printf("YES\n");
            printf("%d %d %d\n", i+1, r-i-1, n-r);
            return;
        }
        else if (minM < maxL) {
            continue;
        }
        // minM > maxL fix
        if (r != n - 1) {
            minM = min(minM, nums[r]);
            r++;
            // maxR = max[r, n-1]
            maxR = 0;
            for (int j = r; j < n; ++j) {
                maxR = max(maxR, nums[j]);
            }
            if (maxL == minM && maxL == maxR) {
                printf("YES\n");
                printf("%d %d %d\n", i+1, r-i-1, n-r);
                return;
            }
        }
    }

    printf("NO\n");
}

int main(int argc, char const *argv[])
{
    int ncases;
    scanf("%d", &ncases);
    while (ncases--)
    {
        solve();
    }
    
    return 0;
}
