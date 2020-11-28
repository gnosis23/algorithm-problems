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
inline void print(const char *text, int u, int v) {
    printf("%s %d %d\n", text, u, v);
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> ans(n);

    int ab, bc, ac, t1, t2, t3;
    print("XOR", 1, 2);
    scanf("%d", &t1);
    print("AND", 1, 2);
    scanf("%d", &t2);
    ab = t1 + (t2 << 1);

    print("XOR", 2, 3);
    scanf("%d", &t3);
    print("AND", 2, 3);
    scanf("%d", &t2);
    bc = t3 + (t2 << 1);

    t1 = t1 ^ t3;
    print("AND", 1, 3);
    scanf("%d", &t2);
    ac = t1 + (t2 << 1);

    // printf("%d %d %d\n", ab, bc, ac);
    ans[0] = (ab + bc + ac) / 2 - bc;
    ans[1] = ab - ans[0];
    ans[2] = bc - ans[1];

    for (int i = 3; i < n; ++i) {
        print("XOR", 1, i+1);
        scanf("%d", &t1);
        ans[i] = t1 ^ ans[0];
    }

    printf("!");
    for (const int a : ans) {
        printf(" %d", a);
    }
    printf("\n");
    return 0;
}
