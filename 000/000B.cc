#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int64;
#define MAXN 1000001
int nums[MAXN];
 
int main(){
  int ncase;
  scanf("%d", &ncase);
  while(ncase--) {
    int n, k;
    int temp;
    scanf("%d %d", &n, &k);
    int64 sum = 0;
    for (int i = 0; i < n*k; ++i) {
      scanf("%d", &nums[i]);
    }
    for (int i = 0; i < k; ++i) {
      int base = (n - 1) / 2 * k;
      int x = nums[base + (n - ((n - 1) / 2)) * i];
      // cout << "choose " << x << endl;
      sum += x;
    }
    printf("%lld\n", sum);
  }
  return 0;
}