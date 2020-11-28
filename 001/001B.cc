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
char buffer[200];

int main(int argc, char const *argv[])
{
    int nCase;
    scanf("%d\n", &nCase);
    while (nCase--) {
        int n, p;
        scanf("%d %d", &n, &p);
        scanf("%s", buffer);
        for (int i = 0; i < p; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            int p;
            for (p = l - 1; p >= 0; --p) {
                if (buffer[p] == buffer[l]) {
                    break;
                }
            }
            if (p >= 0) {
                printf("YES\n");
                continue;
            }
            for (p = r + 1; p < n; ++p) {
                if (buffer[p] == buffer[r]) {
                    break;
                }
            }
            if (p < n) {
                printf("YES\n");
                continue;
            }
            printf("NO\n");
        }
    }
    return 0;
}
