/*
ID:forusac5
LANG:C++
TASK:pprime
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

vector <int> prime;
vector <int> num;
vector <int> ret;
bool isPrime[100001];

bool checkPrime(int n) {
    for (int i = 0; prime[i] <= n / prime[i]; i++) {
        if (n % prime[i] == 0) return false;
    }
    return true;
}

int getNext(int n) {
    int ret = 0;
    while (n) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

void DFS(int deep, int len, int now, int base) {
    if (deep == len) {
        int next = getNext(now);
        num.push_back(now * base + next);
        if (len <= 3) {
            for (int i = 0; i < 10; i++) {
                num.push_back((now * 10 + i) * base + next);
            }
        }
        return;
    }
    int start = 0;
    if (deep == 0)  start++;
    for (int i = start; i < 10; i++) {
        DFS(deep + 1, len, now * 10 + i, base * 10);
    }
}

void producePalindromes() {
     num.push_back(5);
     num.push_back(7);
     for (int i = 1; i <= 4; i++) {
         DFS(0, i, 0, 1);
     }
}


int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    MMset(isPrime, 1);
    prime.push_back(2);
    for (int i = 3; i < 100001; i += 2) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i; j <= 100001 / i; j++) {
                isPrime[j * i] = 1;
            }
        }
    }
    producePalindromes();
    int a, b;
    scanf("%d %d", &a, &b);
    int len = num.size();
    for (int i = 0; i < len; i++) {
       // printf("%d\n", num[i]);
        if (checkPrime((num[i]))) {
            ret.push_back(num[i]);
        }
    }
    sort(ret.begin(), ret.end());
    len = ret.size();
    for (int i = 0; i < len && ret[i] <= b; i++) {
        if (ret[i] >= a)    printf("%d\n", ret[i]);
    }
    return 0;
}
