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
int main(int argc, char const *argv[])
{
    int n, s;
    int a, b;
    vector<int> apples;
    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);
    for (int i = 0; i  < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x <= (a + b)) {
            apples.push_back(y);
        }
    }
    sort(apples.begin(), apples.end());
    
    int ans = 0;
    int len = apples.size();
    for (int i = 0; i < len; ++i) {
        if (s < apples[i]) {
            break;
        }
        ans++;
        s -= apples[i];
    }
    printf("%d\n", ans);
    return 0;
}
