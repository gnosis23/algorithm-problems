/**
 * author: BohaoWang (bj050323@gmail.com)
 * id: https://codeforces.com/contest/1461/problem/C
 * tag: probabilities
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
#define MAXN 1000

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases, n, m;
    cin >> ncases;
    while (ncases--)
    {
        cin >> n >> m;
        vector<int> nums1(n);
        vector<int> nums2(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums1[i];
            nums2[i] = nums1[i];
        }
        sort(nums2.begin(), nums2.end());

        double ans = 0;
        int firstIndex = n-1;
        for(int i = n-1; i >= 0; --i) {
            if (nums1[i] == nums2[i]) {
                firstIndex--;
            }
            else {
                break;
            }
        }

        int r;
        double rest = 1, p;
        for(int i = 0; i < m; ++i) {
            cin >> r >> p;
            r--;
            if (r < firstIndex) continue;
            ans += (rest * p);
            rest -= (rest * p);
            // cout << ans << " " << r << " " << p << endl;
        }

        cout.precision(6);
        cout << std::fixed;
        cout << std::setprecision(6);
        if (firstIndex == -1) {
            cout << 1.0f << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    
    return 0;
}
