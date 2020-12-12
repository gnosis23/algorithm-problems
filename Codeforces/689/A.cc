/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1461/problem/A
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
#define MAXN 3000

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
char buff[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        int id = 1;
        buff[0] = 'a';
        buff[1] = 'c';
        buff[2] = 'b';
        for(int i = 3; i < n; ++i) {
            buff[i] = buff[i-3];
        }
        buff[n] = 0;
        cout << buff << endl;
    }

    return 0;
}
