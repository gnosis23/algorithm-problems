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
#define MAXN 201

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
ll dp[MAXN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll sum = 0;
    dp[11] = 0;
    dp[12] = 1;
    dp[13] = 12;
    sum = 13;
    for(int i = 14; i <= N; ++i) {
        dp[i] = sum * 11 + 11;
        sum += dp[i];
        cout << dp[i] << endl;
    }
    cout << dp[N] << endl;
    return 0;
}
