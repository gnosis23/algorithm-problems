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
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> idMap;
        unordered_map<string, int> counter;
        // 单词有重复
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int id = counter[words[i]];
            counter[words[i]] = id + 1;
            if (id == 0) idMap[words[i]] = cnt++;
        }

        vector<int> vis(n);        
        vector<int> ans;
        int len = s.size();
        int wordLen = words[0].size();
        int sumWords = n * wordLen;
        for (int i = 0; i + sumWords - 1 < len; ++i) {
            fill(vis.begin(), vis.end(), 0);
            int j;
            for (j = 0; j < n; j++) {
                int index = i + j * wordLen;
                auto it = counter.find(s.substr(index, wordLen));
                if (it == counter.end() || (vis[idMap[it->first]] + 1 > it->second)) {
                    break;
                }
                // cout << "substr: " << s.substr(index, wordLen) << " in " << i + j * wordLen << endl;
                vis[idMap[it->first]]++;
            }
            if (j == n) ans.push_back(i);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string str = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution sol;
    vector<int> ans = sol.findSubstring(str, words);
    dumpArray(&ans[0], ans.size());
    return 0;
}
