/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: http://poj.org/problem?id=2484
 * tag: game
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
#include <climits>
#ifdef XDebug
#include "../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    while (true) {
        cin >> n;
        if (n==0)break;
        if (n<=2) puts("Alice");
        else {
            puts("Bob");
        }
    }
    return 0;
}
