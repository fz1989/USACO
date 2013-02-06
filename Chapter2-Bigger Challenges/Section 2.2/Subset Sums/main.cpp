/*
ID:forusac5
LANG:C++
TASK:subset
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
const int MAXN = 1600;
long long dp[MAXN];

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int N;
    scanf("%d", &N);
    int sum = (1 + N) * N / 2;
    if (sum % 2 != 0) {
        printf("0\n");
        return 0;
    }
    MMset(dp, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    printf("%lld\n", dp[sum / 2] / 2);
    return 0;
}
