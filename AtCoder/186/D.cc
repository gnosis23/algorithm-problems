/**
 * author: BohaoWang (bj050323@gmail.com)
 * id:
 * tag:
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
#include "../../debug.h" 
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100
#define all(A) A.begin(), A.end()

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
    cin >> n;
    vector<int> A(n);
    vector<ll> S(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(all(A));
    ll sum = 0;
    S[0] = A[0];
    for (int i = 1; i < n; ++i) {
        sum += (ll)A[i] * i - S[i-1];
        S[i] = S[i-1] + A[i];
    }
    cout << sum << endl;
    return 0;
}
