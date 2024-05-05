#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++)
            p[i] = 1;

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {

            int gcd=0;

            for (int j = i; j <= n; j+=i)
            {
                if (p[j])
                   gcd=__gcd(gcd,j);
            }

            if (gcd==i)
            ans+=i;
        }

        cout << ans << "\n";
    }
}