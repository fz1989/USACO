/*
ID: forusac5
PROG: milk
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
struct Node{
    int amount, price;
    void input() {
        scanf("%d%d", &price, &amount);
    }
}milk[5010];
int N, M;

bool cmp(Node a, Node b) {
    if (a.price == b.price) return a.amount > b.amount;
    else                    return a.price < b.price;
}
int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        milk[i].input();
    }
    sort(milk, milk + M, cmp);

    int ret = 0;
    for (int i = 0; i < M && N > 0; i++) {
        int amount = 0;
        if (N >= milk[i].amount) {
            amount = milk[i].amount;
        } else {
            amount = N;
        }
        ret += amount * milk[i].price;
        N -= amount;
    }
    printf("%d\n", ret);
    return 0;
}
