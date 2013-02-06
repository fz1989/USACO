/*
ID: forusac5
PROG: palsquare
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
int B;
char str1[32], str2[32];

void changeBase(int num, char str[]) {
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

bool check(int num) {
    changeBase(num, str1);
    changeBase(num * num, str2);
    int len = strlen(str2);
    for (int i = 0; i < len / 2; i++) {
        if (str2[i] != str2[len - 1 - i]) return false;
    }
    return true;
}
int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    scanf("%d", &B);
    for (int i = 1; i <= 300; i++) {
        if (check(i)) {
            printf("%s %s\n", str1, str2);
        }
    }
    return 0;
}
