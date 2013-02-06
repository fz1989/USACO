/*
ID:forusac5
LANG:C++
TASK:hamming
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
const int MAXN = 20;
int N, B, D;
vector<int> ret;

int differBit(int a, int b) {
    int n = a ^ b, ret = 0;
    while (n) {
        ret++;
        n = n & (n - 1);
    }
    return ret;
}

bool check(int num, int diff) {
    int len = ret.size();
    for (int i = 0; i < len; i++) {
        if (differBit(ret[i], num) < D) return false;
    }
    return true;
}

int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    scanf("%d%d%d",&N, &B, &D);
    ret.push_back(0);
    for (int i = 1; i < (1 << B); i++) {
        if (check(i, D)) ret.push_back(i);
    }
    int len = min(N, (int)ret.size());
    for (int i = 0; i < len - 1; i++) {
        if ((i + 1) % 10 == 0) printf("%d\n", ret[i]);
        else                    printf("%d ", ret[i]);
    }
    printf("%d\n", ret[len - 1]);
    return 0;
}
