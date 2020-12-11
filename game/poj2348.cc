/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: http://poj.org/problem?id=2348
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
inline bool f(ll a, ll b) {
    ll t;
    if (a > b) swap(a, b);
    if (b % a == 0) return true;
    if (b < a * 2) {
        return !f(b-a, a);
    } else {
        return true;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    ll a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0) break;
        if (f(a, b)) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }
    return 0;
}
