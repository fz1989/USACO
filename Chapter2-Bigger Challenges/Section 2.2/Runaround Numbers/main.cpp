/*
ID:forusac5
LANG:C++
TASK:runround
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <string>
#define MMset(a,b) memset(a, b, sizeof(a))
using namespace std;
const int MAXN = 64;
int N;
bool vis[MAXN];
char str[MAXN];
bool digs[256];

bool check(int num) {
    MMset(str, '\0');
    MMset(vis, 0);
    MMset(digs, 0);
    sprintf(str, "%d", num);
    int len = strlen(str), now = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '0') return false;
        if (digs[str[i]])   return false;
        digs[str[i]] = 1;
    }
    for (int i = 0; i < len; i++) {
        now = (now + (str[now] - '0')) % len;
        if (vis[now]) return false;
        vis[now] = 1;
    }
    return now == 0;
}

int main()
{
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    scanf("%d", &N);
    while (1) {
        N++;
        if (check(N)) {
            printf("%d\n", N);
            return 0;
        }
    }
    return 0;
}
