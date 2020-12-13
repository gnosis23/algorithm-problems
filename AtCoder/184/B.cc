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
#define MAXN 100

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
char buff[200010];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    cin >> buff;
    for(int i = 0; i < n; ++i) {
        if (buff[i] == 'x') {
            x--;
            if (x<0)x=0;
        } else {
            x++;
        }
    }
    cout << x << endl;
    return 0;
}
