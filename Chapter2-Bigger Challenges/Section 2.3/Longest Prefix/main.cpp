/*
ID: forusac5
PROG: prefix
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
char  dict[236], str[201000];
bool dp[201000];
struct Tire {
    int next[26];
    bool flag;
    void init() {
        MMset(next, -1);
        flag = false;
    }
}trie[2013];
int ncnt = 0;

void insert(char *in) {
    int len = strlen(in);
    int pos = 0, now = 0;
    for (int i = 0; i < len; i++) {
        pos = in[i] - 'A';
        if (trie[now].next[pos] == -1) {
            trie[++ncnt].init();
            trie[now].next[pos] = ncnt;
        }
        now = trie[now].next[pos];
    }
    trie[now].flag = true;
}

bool search(char *in) {
    int len = strlen(in);
    int pos = 0, now = 0;
    for (int i = 0; i < len; i++) {
        pos = in[i] - 'A';
        if (trie[now].next[pos] == -1) {
            return false;
        } else {
            now = trie[now].next[pos];
        }
    }
    return trie[now].flag;
}

bool match(int start, int end) {
    char tmp[20];
    MMset(tmp, '\0');
    for (int i = start; i <= end; i++) {
        tmp[i - start] = str[i];
    }
    return search(tmp);
}


int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    trie[0].init();
    while (scanf("%s", dict) != 0) {
        if (dict[0] == '.') {
            break;
        }
        insert(dict);
    }
    int pos = 1;
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch != '\n') str[pos++] = ch;
    }
    dp[0] = 1;
    int ret = 0;
    for (int i = 1; i < pos; i++) {
        for (int j = max(0, i - 10); j < i; j++) {
            if (dp[j] && match(j + 1, i)) {
                dp[i] = 1;
                break;
            }
        }
        if (dp[i])  ret = i;
    }
    printf("%d\n", ret);
    return 0;
}
