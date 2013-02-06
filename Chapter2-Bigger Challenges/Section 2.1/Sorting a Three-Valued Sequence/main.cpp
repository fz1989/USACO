/*
ID:forusac5
LANG:C++
TASK:sort3
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
const int MAXN = 1024;
using namespace std;
int num[MAXN];
int cnt[4], N;
int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", num + i);
        cnt[num[i]]++;
    }
    int ret = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
        if (num[i] == 1) {
            if (i >= cnt[1])  ret++;
        }
        if (num[i] == 2) {
            if (i >= cnt[1] + cnt[2])   cnt1++;
        }
        if (num[i] == 3) {
            if (i >= cnt[1] && i < cnt[1] + cnt[2]) cnt2++;
        }
    }
    ret += max(cnt1, cnt2);
    printf("%d\n", ret);
    return 0;
}
