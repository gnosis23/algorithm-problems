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
    while (nCase--)
    {
        int n;
        scanf("%d", &n);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back((i + 1) % n);
            printf("%d", (i + 1) % n + 1);
            if (i != n -1)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
