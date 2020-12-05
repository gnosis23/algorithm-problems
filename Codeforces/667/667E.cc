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
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    ll ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (i == (n / 2) || i == (n)) continue;
        ans *= i;
    }
    printf("%lld\n", ans);
    return 0;
}
