#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;

int mem[max_n + 1];

int nth_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (mem[n] != -1) return mem[n];
    mem[n] = nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
    return mem[n];
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    memset(mem, empty_value, sizeof(mem));
    
    return 0;
}
