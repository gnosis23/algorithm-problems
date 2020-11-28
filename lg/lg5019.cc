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
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

// CODE HERE
int nums[100000];
vector<pair<int,int>> nums2;
int main(int argc, char const *argv[])
{
    int sum, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            nums2.push_back({nums[i], 1});
        } else if (nums[i] == nums[i - 1]) {
            nums2.back().second += 1;
        } else {
            nums2.push_back({nums[i], 1});
        }
    }

    int size = nums2.size();
    // for (int i = 0; i < size; i++) {
    //     printf("%d %d\n", nums2[i].first, nums2[i].second);
    // }

    int cnt = 0;
    int ans = n;
    for (int i = 0; i < size; ++i) {
        cnt++;
        if (
            (i == size - 1) || 
            ((nums2[i].first + 1) != nums2[i+1].first)
        ) {
            ans = min(ans, cnt);
            cnt = 0;
        } 
        else if ((nums2[i].second > nums2[i+1].second)) {
            ans = min(ans, cnt);
        } 
        else if (nums2[i].second < nums2[i+1].second) {
            cnt = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}
