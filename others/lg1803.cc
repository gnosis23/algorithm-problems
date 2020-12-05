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
using namespace std;

typedef long long ll;

// CODE HERE
// 最优解总是取结束小的线段
// 反证：如果最优解不是取结束小的线段，我们可以用最小线段替换
vector<int> ans(1000001, 0);
vector<pair<int, int>> contests;

int main(int argc, char const *argv[])
{
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int s, e;
        scanf("%d %d", &s, &e);
        contests.push_back({s, e});
    }
    sort(contests.begin(), contests.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int ans = 0;
    int lastIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (contests[i].first >= lastIndex) {
            lastIndex = contests[i].second;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
