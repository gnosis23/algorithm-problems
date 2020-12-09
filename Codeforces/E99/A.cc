/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
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
#define MAXN 1000

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
char text[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases, n;
    cin >> ncases;
    while (ncases--)
    {
        cin >> text;
        cout << strlen(text) << endl;
    }
    
    return 0;
}
