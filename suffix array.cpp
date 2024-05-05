#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 700;
const int N = 1e6 + 5;
const int M = 998244353;

int32_t main()
{

    string s;
    cin >> s;

    s += '$';

    int n = s.size();

    vector<int> p(n), c(n);

    {
        vector<pair<char, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;

    while ((1 << k) < n)
    {

        vector<pair<pair<int, int>, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        string t;
        cin >> t;

        t += '~';

        auto good = [&](int m)
        {
            string s1 = s.substr(p[m], n - p[m]);

            return s1 <= t;
        };

        int l = 0, r = n;
        while (r > l + 1)
        {
            int m = (l + r) / 2;

            if (good(m))
                l = m;
            else
                r = m;
        }

        string s1 = s.substr(p[l], n - p[l]);   

        t.pop_back();

        if (s1.size() >= t.size())
        {
            s1 = s1.substr(0, t.size());
        }

        if (s1 == t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
