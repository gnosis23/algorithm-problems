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
int nums[2000001];
int main(int argc, char const *argv[])
{
    int ncases;
    scanf("%d", &ncases);
    while(ncases--) {
        map<int, int> count;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            if (i == 0) {
                count[nums[i]] = 0;
            } 
            else if (nums[i] != nums[i - 1]) {
                count[nums[i]]++;
            }
        }
        int ans = INT_MAX;
        int index = -1;
        for (auto& x : count) {
            if (x.second < ans) {
                if (x.first != nums[n-1]) {
                    ans = min(ans, x.second + 1);
                } else {
                    ans = min(ans, x.second);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
