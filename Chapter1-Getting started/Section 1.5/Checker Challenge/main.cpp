/*
ID:forusac5
LANG:C++
TASK:checker
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

using namespace std;

int MOD, sum = 0, tmp[20], N;

int calc(int n) {
    int len = 0;
    while (n) {
        n /= 2;
        len++;
    }
    return len;
}

void DFS(int pre, int prel, int prer, int deep) {
    int now = pre | prel | prer;
    int next = (now) ^ (MOD - 1);
    if (deep == N) {
        if (sum < 3) {
            for (int i = 0; i < N; i++) {
                printf("%d", calc(tmp[i]));
                if (i + 1 < N) printf(" ");
                else            printf("\n");
            }
        }
        sum++;
        return;
    }
    while (next) {
        tmp[deep] = next - (next & (next - 1));
        int nnext = tmp[deep] | pre;
        int nprel = tmp[deep] | prel;
        int nprer = tmp[deep] | prer;
        DFS(nnext, nprel >> 1, (nprer << 1) % MOD, deep + 1);
        next = (next & (next - 1));
    }
}

int main()
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &N);
    MOD = 1 << N;
    DFS(0, 0, 0, 0);
    printf("%d\n", sum);
    return 0;
}
