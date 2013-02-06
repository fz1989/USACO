/*
ID:forusac5
LANG:C++
TASK:sprime
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
#define MMset(a, b) memset(a, b, sizeof(a))
using namespace std;
vector <int> prime, ret;
bool isPrime[10001];
int num[] = {2, 3, 5, 7};
int add[] = {1, 3, 7, 9};

void makePrime() {
    MMset(isPrime, 1);
    prime.push_back(2);
    for (int i = 3; i < 10001; i += 2) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i; j <= 10001 / i; j++) {
                isPrime[j * i] = 1;
            }
        }
    }
}
bool checkPrime(int n) {
    if (n == 2) return true;
    int len = prime.size();
    for (int i = 0; prime[i] <= n / prime[i]; i++) {
        if (n % prime[i] == 0) return false;
    }
    return true;
}

void DFS(int deep, int len, int now) {
    if (deep == len) {
        ret.push_back(now);
        return;
    }
    int *arr;
    if (deep == 0)  arr = num;
    else            arr = add;
    for (int i = 0; i < 4; i++) {
        int next = now * 10 + arr[i];
        if (checkPrime((next))) DFS(deep + 1, len, next);
    }
}

int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    int N;
    scanf("%d", &N);
    makePrime();
    DFS(0, N, 0);
    sort(ret.begin(), ret.end());
    int len = ret.size();
    for (int i = 0; i < len; i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}
