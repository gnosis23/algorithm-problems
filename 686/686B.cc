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
int arr[200000];
int main(int argc, char const *argv[])
{
    int nCases;
    scanf("%d", &nCases);
    while (nCases--)
    {
        map<int, int> nums;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d", &t);
            nums[t]++;
            arr[i] = t;
        }
        
        int ans = -1;
        for(auto& x : nums) {
            // printf("(%d %d)\n", x.first, x.second);
            if (x.second == 1) {
                ans = x.first;
                break;
            }
        }
        // printf("ans = %d\n", ans);
        if (ans == -1) {
            printf("-1\n");
        } else {
            for (int i = 0; i < n; ++i) {
                if (arr[i] == ans) {
                    printf("%d\n", i + 1);
                    break;
                }
            }
        }
    }
    
    return 0;
}
