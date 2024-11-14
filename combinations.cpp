#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;

int32_t main()
{

    vector<int> fact(N + 1);
    fact[0] = 1;

    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % M;

    auto P = [&](int a, int b)
    {
        int res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % M;
            b = b >> 1;
            a = a * a % M;
        }

        return res;
    };

    // cout << P(2, 3) << "\n";

    auto MI = [&](int a)
    {
        return P(a, M - 2);
    };

    auto nCr = [&](int n, int r)
    {
        if (r > n)
            return 0LL;
        int res = fact[n] * MI(fact[r] * fact[n - r] % M) % M;
        return res;
    };

    int n, k;
    cin >> n >> k;

    int c = min(k + 1, n);
    int d = 1;
    int i = 0;
    int j = 0;

    int ans = 0;

    while (i * (c + 1) <= n)
    {
        int cur = nCr(n, n - i) * nCr(n - 1 + n - i * (c + 1), n - i * (c + 1)) % M;
        cout << cur << "\n";
        ans += d * cur;
        ans += M;
        ans %= M;

        d *= -1;
        i++;
    }

    cout<<"Brute\n";

    cout<<nCr(29,15)%M<<"\n";
    cout<<15*nCr(21,7)<<"\n";

    cout << ans << "\n";
}
