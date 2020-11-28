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
#include <algorithm>
using namespace std;

typedef long long ll;

// CODE HERE
#define MAXN 1600
#define SLOT 10000
char buffer[MAXN];
hash<string> hasher;

struct Node {
    Node(): next(nullptr) {}
    string text;
    Node* next;
};
Node hashTable[SLOT];
int poolSize = 0;
Node pool[SLOT+1];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buffer);
        string x(buffer);
        size_t hashCode = hasher(x);
        // printf("%zu\n", hashCode);
        Node* ptr = &hashTable[hashCode % SLOT];
        bool find = false;
        while (ptr->next) {
            ptr = ptr->next;
            if (ptr->text == x) {
                find = true;
                break;
            }
        }
        if (!find) {
            Node* tmp = &pool[poolSize++];
            tmp->text = x;
            tmp->next = nullptr;
            ptr->next = tmp;
        }
    }
    printf("%d\n", poolSize);
    return 0;
}
