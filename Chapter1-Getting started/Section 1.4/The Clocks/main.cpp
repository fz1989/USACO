/*
ID: forusac5
PROG: clocks
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
int trans[9][9];
char cmd[9][9] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int cmdlen[9];
int state[9];
vector <int> ret, tmp;

bool check() {
    for (int i = 0; i < 9; i++) {
        if (state[i] != 0)  return false;
    }
    return true;
}

void DFS(int deep) {
    if (deep == 9) {
        if (check()) {
            if (ret.size() == 0 || tmp < ret) {
                ret.clear();
                int len = tmp.size();
                for (int i = 0; i < len; i++) {
                    ret.push_back(tmp[i]);
                }
            }
        }
        return;
    }
    DFS(deep + 1);
    for (int i = 0; i < 3; i++) {
        tmp.push_back(deep + 1);
        for (int j = 0; j < cmdlen[deep]; j++) {
            int now = cmd[deep][j] - 'A';
            state[now] = (state[now] + 3) % 12;
        }
        DFS(deep + 1);
    }
    for (int i = 0; i < 3; i++) {
        tmp.pop_back();
    }
    for (int j = 0; j < cmdlen[deep]; j++) {
            int now = cmd[deep][j] - 'A';
            state[now] = (state[now] + 3) % 12;
    }
}

int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    for (int i = 0; i < 9; i++) {
        cmdlen[i] = strlen(cmd[i]);
    }
    for (int i = 0; i < 9; i++) {
        scanf("%d", state + i);
        state[i] %= 12;
    }
    DFS(0);
    int len = ret.size();
    for (int i = 0; i < len; i++) {
        printf("%d%c", ret[i], (i + 1 == len) ? '\n' : ' ');
    }
    return 0;
}
