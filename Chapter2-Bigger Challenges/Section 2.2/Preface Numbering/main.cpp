/*
ID:forusac5
LANG:C++
TASK:preface
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
int score[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string bits[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
char ch[8]={'I','V','X','L','C','D','M'};
int N;
int tot[256];

void adder(int cnt, string str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        tot[str[i]] += cnt;
    }
}

void calc(int num) {
    for (int i = 0; i < 13; i++) {
        if (num >= score[i]) {
            adder(num / score[i], bits[i]);
            num -= num / score[i] * score[i];
        }
    }
}
int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        calc(i);
    }
    for (int i = 0; i < 7; i++) {
        if (tot[ch[i]] != 0) {
            printf("%c %d\n", ch[i], tot[ch[i]]);
        }
    }
    return 0;
}
