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
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define INF 1e9
#define MAXN 100

inline void dumpGraph(int graph[][MAXN], int r, int c) {
#ifdef XDebug    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
}

inline void dumpArray(int *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

// CODE HERE
void print(int base, bool first) {
    if (first) {
        cout << 1;
    } else {
        cout << " 1";
    }
    if (base == 1) return;
    for(int i = 0; i < base-2; ++i) {
        cout << " 0";
    }
    cout << " 1";
}

int main(int argc, char const *argv[])
{
    int ncase;
    cin >> ncase;
    while (ncase--)
    {
        ll k;
        cin >> k;
        if (k % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        ll lens = 0;
        ll base = 0;
        ll num = k;
        bool first = true;
        while (num > 0)
        {
            num /= 2;
            base++;
            if (num & 1) {
                lens += base;
                // print(base, first);
                first = false;
            }
        }
        if (lens <= 2000) {
            cout << lens << endl;
            num = k;
            first = true;
            base = 0;
            while (num > 0)
            {
                num /= 2;
                base++;
                if (num & 1) {
                    lens += base;
                    print(base, first);
                    first = false;
                }
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
