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
vector<ll> v1;
vector<ll> v2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    vector<ll> dp(N+1,INF);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    ll ans = 0;
    int n1 = N/2;
    int n2 = N - n1;
    int s1 = 1<<n1;
    int s2 = 1<<n2;
    for(int i = 0; i < s1; ++i) {
        ll sum = 0;
        for(int j = 0; j < n1; ++j) {
            if (i & (1<<j)) {
                sum += A[j];
            }
        }
        if (sum <= T) v1.push_back(sum);
    }
    for(int i = 0; i < s2; ++i) {
        ll sum = 0;
        for(int j = 0; j < n2; ++j) {
            if (i & (1<<j)) {
                sum += A[n1+j];
            }
        }
        if (sum <= T) v2.push_back(sum);
    }

    int size1 = v1.size();
    int size2 = v2.size();
    sort(v2.begin(), v2.end());
    for (int i = 0; i < size1; ++i) {
        ll x = v1[i];
        auto it = lower_bound(v2.begin(), v2.end(), T-x);
        if (it != v2.end() && (*it + x <= T)) {
            ans = max(ans, *it + x);
        }
        if (it != v2.begin() && (*(it-1) + x <= T)) {
            ans = max(ans, *(it-1) + x);
        }
    }
    
    cout << ans << endl;
    return 0;
}
