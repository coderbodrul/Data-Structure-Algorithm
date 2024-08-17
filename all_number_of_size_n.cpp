#include <bits/stdc++.h>
#define mx 10
using namespace std;

int n;
int number[mx + 1];

void generateNumbers(int idx) {
    if (idx == n + 1) {
        for (int i = 1; i <= n; i++) cerr << number[i] << " \n"[i == n];
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        number[idx] = i;
        generateNumbers(idx + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = 5;
    generateNumbers(0);
    
    return 0;
}