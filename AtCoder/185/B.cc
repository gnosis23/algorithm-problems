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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;
    int a, b;
    int rest = n;
    int time = 0;
    bool fail = false;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        rest -= (a - time);
        // cout << "rest: " << rest << endl;
        if (rest <= 0) {
            fail = true;
            break;
        }
        rest += (b - a);
        // cout << "rest: " << rest << endl;
        if (rest > n) rest = n;
        time = b;
    }
    rest -= (t - time);
    // cout << "rest: " << rest << endl;
    if (rest <= 0) {
        fail = true;
    }
    if (fail) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
