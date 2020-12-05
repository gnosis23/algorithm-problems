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

int main(int argc, char const *argv[])
{
    int n, t;
    scanf("%d %d", &n, &t);
    vector<pair<int, int>> items;
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        items.push_back({a, b});
    }
    sort(items.begin(), items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second * b.first > b.second * a.first;
    });

    int rest = t;
    double ans;
    for (int i = 0; i < n; ++i) {
        if (items[i].first <= rest) {
            rest -= items[i].first;
            ans += items[i].second;
        } else {
            ans += ((double) rest * items[i].second / items[i].first);
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
