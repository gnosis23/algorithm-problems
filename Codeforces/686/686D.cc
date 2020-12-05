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
#include <algorithm>
using namespace std;

typedef long long ll;

// CODE HERE

int main(int argc, char const *argv[])
{
    int ncases;
    scanf("%d", &ncases);
    while(ncases--) {
        ll n;
        scanf("%lld", &n);
        ll copy = n;
        unordered_map<ll,int> primes;
        int end = floor(sqrt(n));
        for (int i = 2; i <= end && n != 1; i++) {
            while (n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
        if (n != 1) {
            primes[n]++;
        }
        
        int maxp = 0;
        ll maxk = 0;
        for (auto& i : primes) {
            // printf("p [%d * %d]\n", i.first, i.second);
            if (i.second > maxp) {
                maxp = i.second;
                maxk = i.first;
            }
        }

        printf("%d\n", maxp);
        for (int i = 0; i < maxp; i++) {
            if (i != maxp - 1) {
                printf("%lld", maxk);
            } else {
                printf("%lld", copy);
            }
            if (i != maxp - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
            copy /= maxk;
        }
    }
    return 0;
}
