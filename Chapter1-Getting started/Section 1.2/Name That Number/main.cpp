/*
ID: forusac5
PROG: namenum
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
int codeBoard[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
struct DICT {
    char name[20];
    long long key;
    void calc() {
        int len = strlen(name);
        key = 0;
        for (int i = 0; i < len; i++) {
            int dig = codeBoard[name[i] - 'A'];
            if (dig == -1) {
                key = -1;
                return;
            } else {
                key = key * 10 + dig;
            }
        }
    }
}dict[5000];

int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    FILE *in=fopen ("dict.txt", "r");
    int tot = 0;
    while (fscanf(in, "%s", dict[tot].name) != EOF) {
        dict[tot].calc();
        tot++;
    }
    long long ID = 0;
    cin >> ID;
    int cnt = 0;
    for (int i = 0; i < tot; i++) {
        if (ID == dict[i].key) {
            printf("%s\n", dict[i].name);
            cnt++;
        }
    }
    if (cnt == 0) printf("NONE\n");
    fclose(in);
    return 0;
}
