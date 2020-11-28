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
int nums[5001];
int main(int argc, char const *argv[])
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int a = 0;
        int b = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[a]) {
                b = i;
                break;
            }
        }
        if (b == -1) {
            printf("NO\n");
        } else {
            printf("YES\n");
            printf("%d %d\n", a + 1, b + 1);
            for (int i = 0; i < n; ++i) {
                if (i == a || i == b) continue;
                if (nums[a] == nums[i]) {
                    printf("%d %d\n", b + 1, i + 1);
                } else {
                    printf("%d %d\n", a + 1, i + 1);
                }
            }
        }
    }
    return 0;
}
