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
    scanf("%d", &n);
    vector<pair<int, int>> items;
    int w;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w);
        items.push_back({w, i+1});
    }
    sort(items.begin(), items.end());
    double sum = 0;
    int from = 0;
    for (int i = 0; i < n; ++i) {
        sum += from;
        from += items[i].first;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", items[i].second);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
    sum /= n;
    printf("\n%.2lf\n", sum);
    return 0;
}
