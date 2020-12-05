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
int arr[1000];
int main(int argc, char const *argv[])
{
    int nCase ;
    scanf("%d", &nCase);
    while (nCase--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] == 1) {
                r = i;
                break;
            }
        }
        int ans = 0;
        for (int i = l; i < r; ++i) {
            if (arr[i] == 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
