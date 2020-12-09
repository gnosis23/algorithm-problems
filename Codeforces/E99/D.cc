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
#define MAXN 1000

#ifndef XDebug
#define dumpArray(...) 42
#define dumpGraph(...) 42
#endif

// CODE HERE
bool need[MAXN];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, x;
        int cnt = 0;
        cin >> n >> x;
        vector<int> nums(n);
        vector<int> nums2(n);
        memset(need, 0, sizeof(need));
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
            nums2[i] = nums[i];
        }
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < n; ++i) {
            if (nums[i] != nums2[i]) {
                need[i] = true;
                cnt++;
            }
        }
        if (cnt == 0 || n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int k = 0;
        for(k = 0; k < n; ++k) {
            if (need[k]) {
                if (k == n-1) {
                    if (nums[k-1] <= nums[k]) {
                        k++;
                        break;
                    }
                    else if (nums[k] < x) {
                        cout << "break:" << k << endl;
                        break;
                    }
                }
                else if (nums[k] < x) {
                    cout << "break:" << k << endl;
                    break;
                }
            }
            if (nums[k] > x && cnt > 0) {
                int t = x;
                x = nums[k];
                nums[k] = t;
                ans++;
            }
            if (need[k]) {
                cnt--;
            }
        }
        if (k != n) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
