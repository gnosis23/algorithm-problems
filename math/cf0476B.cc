/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/476/B
 * tag: dp 
 */
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
#include <cassert>
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
ll nCk(int n, int k) {
    ll s = 1;
    k = min(k, n-k);
    for (ll d = 1; d <= k; ++d) {
        s *= n--;
        s /= d;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, t;
    string a,b;
    cin >> a >> b;
    n = a.size();

    int no = 0;
    int last1 = 0;
    int last2 = 0;
    int nq = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '+') last1++;
        else last1--;
        if (b[i] == '+') last2++;
        else if (b[i] == '-') last2--;
        else nq++;
    }

    double result = 0;
    int diff = last1 - last2;
    int nPositive = (diff + nq) / 2;
    int nNegtive = nq - nPositive;
    // 2 * nPos = diff + Q

    if ((diff + nq) % 2 || (diff + nq) < 0 || nPositive > nq) {
        result = 0;
    }
    else {
        result = (double)nCk(nq, nPositive) / pow(2, nq);
    }
    
    cout.precision(12);
    cout << std::fixed;
    cout << std::setprecision(12);
    cout << result << endl;
    return 0;
}
