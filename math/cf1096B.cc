/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/problemset/problem/1096/B
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
#include "../debug.h" 
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

int main(int argc, char const *argv[])
{
    ll modulo = 998244353 ;
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<PII>> S(26);
    char ch = str[0];
    PII chLen = {0, 1};
    for (int i = 1; i < n; ++i) {
        if (str[i] == ch) {
            chLen.second++;
        }
        else {
            S[ch - 'a'].push_back(chLen);
            ch = str[i];
            chLen.first = i;
            chLen.second = 1;
        }
    }
    S[ch - 'a'].push_back(chLen);

    char firstChar = str[0];
    char lastChar = str[n-1];
    ll ans = 0;
    for (int i = 0; i < 26; ++i) {
        int size = S[i].size();
        if ((firstChar - 'a' != i) && (lastChar - 'a' != i)) {
            // do nothing
        }
        else if (lastChar - 'a' != i) {
            ans = (ans + S[i][0].second) % modulo;
        }
        else if (firstChar - 'a' != i) {
            ans = (ans + S[i][size - 1].second) % modulo;
        }
        else {
            if (size == 1) {
                ans = (ans + S[i][0].second) % modulo;
            }
            else {
                ans = (ans + (ll)S[i][0].second * S[i][size-1].second) % modulo;
                ans = (ans + S[i][0].second) % modulo;
                ans = (ans + S[i][size-1].second ) % modulo;
                // cout << i + 'a' << " " << S[i][0].second << endl;
                // cout << i + 'a' << " " << S[i][size-1].second << endl;
            }
        }
    }
    ans = (ans + 1) % modulo;

    cout << ans << endl;
    return 0;
}
