#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int32_t main()
{

    int n, m;
    cin >> n >> m;

    // x*x <=n  x*(x+1)<=m

    int l = 0, r = 1e9;

    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (m * m <= n)
            l = m;
        else
            r = m;
    }

    int x = l;

    while (r > l + 1)
    {
        int x = (l + r) / 2;
        if (x * (x + 1) <= m)
            l = m;
        else
            r = m;
    }

    auto solve = [&](int n)
    {
        int l = 0, r = 1e9;
        while (r > l + 1)
        {
            int m = (l + r) / 2;
            if (m * (m + 1) / 2 <= n)
                l = m;
            else
                r = m;
        }

        return l;
    };

    int y = l;

    int z = min(x, y);
    n -= z * z;

    int ans = 0;

    if (n == 0)
    {
        m -= z * (z - 1);
        ans += z;
        ans += z - 1;
        ans += solve(m);
        cout << ans << "\n";

        return 0;
    }

    if (m == 0)
    {
        ans += 2 * z;
        ans += solve(n);
        cout << ans << "\n";
        return 0;
    }
}
