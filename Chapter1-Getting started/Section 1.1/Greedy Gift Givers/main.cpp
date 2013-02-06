/*
ID: forusac5
PROG: gift1
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
int N, totalMoney, totalPeople, moneyCount;
vector <string> name;
map<string, int>money;
string people, giver, receiver;
int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> people;
        name.push_back(people);
        money[people] = 0;
    }
    for (int i = 0; i < N; i++) {
        cin >> giver >> totalMoney >> totalPeople;
        if (totalPeople == 0 || totalMoney == 0) continue;

        moneyCount = totalMoney / totalPeople;
        for (int j = 0; j < totalPeople; j++) {
            cin >> receiver;
            money[receiver] += moneyCount;
        }
        money[giver] -= moneyCount * totalPeople;
    }
    for (int i = 0; i < N; i++) {
        cout << name[i] << ' ' << money[name[i]] <<endl;;
    }
    return 0;
}
