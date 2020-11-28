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
    int nCase;
    scanf("%d", &nCase);
    while(nCase--) {
        int n;
        scanf("%d", &n);
        if (n == 1)printf("0\n");
        else if (n == 2)printf("1\n");
        else if (n == 3)printf("2\n");
        else if (n % 2 == 0)printf("2\n");
        else printf("3\n");
    }
    return 0;
}
