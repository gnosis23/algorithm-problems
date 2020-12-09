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
#define MAXN 1001000

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
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= 2000; ++i) {
            sum += i;
            if (sum == n) {
                cout << i << endl;
                break;
            }
            if (sum - n == 1) {
                cout << i + 1 << endl;
                break;
            }
            if (sum > n) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
