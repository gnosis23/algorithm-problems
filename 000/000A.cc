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

typedef long long ll;

#define MAXN 1002
char buf[MAXN];
 
int main(){
  int ncase;
  scanf("%d", &ncase);
  while(ncase--) {
    int n, c0, c1, h;
    scanf("%d %d %d %d", &n, &c0, &c1, &h);
    scanf("%s", buf);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (buf[i] == '0') {
        sum += (((h + c1) > c0) ? c0 : (h + c1));
      } else {
        sum += (((h + c0) > c1) ? c1 : (h + c0));
      }
    }
    printf("%d\n", sum);
  }

  return 0;
}