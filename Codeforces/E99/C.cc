/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: http://codeforces.com/contest/1455/problem/C
 * tag: gamble
 **/
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
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int a, b;
        cin >> a >> b;
        cout << a-1 << " " << b << endl;
    }
    return 0;
}
