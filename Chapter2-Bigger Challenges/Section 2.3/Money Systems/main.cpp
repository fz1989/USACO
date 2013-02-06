/*
ID: forusac5
PROG: money
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
#define empty 0
#define add 1
#define minus 2
using namespace std;
const int MAXN = 10001;
long long dp[MAXN];
int N, V;
int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%d %d", &V, &N);
    dp[0] = 1;
    for (int i = 0; i < V; i++) {
        int num = 0;
        scanf("%d", &num);
        for (int j = num; j <= N; j++) {
            dp[j] += dp[j - num];
        }
    }
    printf("%lld\n", dp[N]);
    return 0;
}
