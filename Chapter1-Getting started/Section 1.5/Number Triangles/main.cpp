/*
ID:forusac5
LANG:C++
TASK:numtri
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
#define MMset(a, b) memset(a, b, sizeof(a))
using namespace std;
const int MAXN = 1024;
int dp[MAXN][MAXN], N;
int num[MAXN][MAXN];

int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    scanf("%d", &N);
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];
            if (i == N) ret = max(ret, dp[i][j]);
        }
    }
    printf("%d\n", ret);
    return 0;
}
