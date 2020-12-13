/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
 **/
#include <iostream>
#include <iomanip>
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
#include <list>
#include <algorithm>
#include <climits>
#ifdef XDebug
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 101

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
double dp[MAXN][MAXN][MAXN];

double solve(int x, int y, int z) {
    if (dp[x][y][z]) return dp[x][y][z];
    if (x == 100 || y == 100 || z == 100) return 0;
    double ans = (solve(x + 1,y,z) + 1) * x / (x+y+z);
    ans += (solve(x,y+1,z) + 1) * y / (x+y+z);
    ans += (solve(x,y,z+1) + 1) * z / (x+y+z);
    dp[x][y][z] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.9f\n", solve(a,b,c));
    return 0;
}
