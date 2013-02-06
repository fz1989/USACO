/*
ID: forusac5
PROG: dualpal
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
int N, S;
char str[32];

void changeBase(int num, int B, char str[]) {
    int len = 0;
    while (num) {
        int c = num % B;
        if (c < 10) str[len++] = c + '0';
        else        str[len++] = c - 10 + 'A';
        num /= B;
    }
    reverse(str, str + len);
    str[len] = '\0';
}

bool check(int num, int B) {
    changeBase(num, B, str);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}
int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    scanf("%d %d", &N, &S);
    while (1) {
        S++;
        int cnt = 0;
        for (int i = 2; i <= 10; i++) {
            if (check(S, i)) cnt++;
        }
        if (cnt >= 2) {
            printf("%d\n", S);
            N--;
        }
        if (N == 0) break;
    }
    return 0;
}
