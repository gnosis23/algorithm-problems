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
int nums[300001];
int main(int argc, char const *argv[])
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int n;
        scanf("%d", &n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            m = max(nums[i], m);
        }
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == m && (i >= 1) && nums[i] > nums[i - 1]) {
                index = i + 1;
                break;
            }
            if (nums[i] == m && (i < n - 1) && nums[i] > nums[i + 1]) {
                index = i + 1;
                break;
            }
        }
        printf("%d\n", index);
    }
    return 0;
}
