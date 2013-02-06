/*
ID: forusac5
PROG: crypt1
LANG: C++
*/
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
int N, ret = 0;
bool vis[10];
int dig[5], num[10];

int getNum(int l, int r) {
    int ret = 0;
    for (int i = l; i < r; i++) {
        ret = ret * 10 + dig[i];
    }
    return ret;
}
bool check(int n, int len) {
    int tlen = 0;
    while (n) {
        int now = n % 10;
        if (!vis[now])  return false;
        tlen++;
        n /= 10;
    }
    return  tlen == len;
}

void DFS(int deep) {
    if (deep == 5) {
        int A = getNum(0, 3);
        int B = getNum(3, 5);
        if (check(A * dig[3], 3)
        &&  check(A * dig[4], 3)
        &&  check(A * B, 4))
            ret++;
        return;
    }
    for (int i = 0; i < N; i++) {
        dig[deep] = num[i];
        DFS(deep + 1);
    }
}
int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    scanf("%d", &N);
    MMset(vis, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d", num + i);
        vis[num[i]] = 1;
    }
    DFS(0);
    printf("%d\n", ret);
    return 0;
}
