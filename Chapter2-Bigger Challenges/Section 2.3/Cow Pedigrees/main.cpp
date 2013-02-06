/*
ID: forusac5
PROG: nocows
LANG: C++
*/
#include <iostream>
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
const int MAXK = 101;
const int MAXN = 201;
const int MOD = 9901;
int dp[MAXK][MAXN], sum[MAXK][MAXN];
int N, K;

int main()
{
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    scanf("%d%d", &N, &K);
    MMset(dp, 0);
    dp[1][1] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j+=2) {
            for (int k = 1; k <= j - 1 - k; k++) {
                int tmp = sum[i - 2][k] * dp[i - 1][j - 1 - k]
                        + sum[i - 2][j - 1 - k] * dp[i - 1][k]
                        + dp[i - 1][k] * dp[i - 1][j - 1 - k];
                if (k != j - 1 - k) tmp *= 2;
                dp[i][j] = (dp[i][j] + tmp) % MOD;
            }
        }
        for (int j = 0; j <= N; j++) {
            sum[i - 1][j] += (dp[i - 1][j] + sum[i - 2][j]);
            sum[i - 1][j] %= MOD;
        }
    }

    printf("%d\n", dp[K][N]);
    return 0;
}
