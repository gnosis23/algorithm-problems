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
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int end;
        scanf("%d", &end);
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            int start = i;
            int len = 1;
            while (start <= 9999) {
                ans += len;
                if (start == end) {
                    goto next;
                }
                // printf("start %d\n", start);
                start = start * 10 + i;
                len++;
            }
        }
next:
        printf("%d\n", ans);
    }
    return 0;
}
