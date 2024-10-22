#include <bits/stdc++.h>
#define int long long
#define mx 100000007

using namespace std;
int isp[mx / 32];

void not_prime(int n) {
    int in = n / 32;
    int pos = n % 32;
    isp[in] |= (1 << pos);
}

bool ck(int n) {
    int in = n / 32;
    int pos = n % 32;
    if (isp[in] & (1 << pos)) return false;
    return true;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    not_prime(0);
    not_prime(1);
    for (int i = 4; i <= mx; i += 2) not_prime(i);
    for (int i = 3; i <= mx; i += 2) {
        if (ck(i)) {
            for (int j = i * i; j <= mx; j += i) not_prime(j);
        }
    }

    return 0;
}
