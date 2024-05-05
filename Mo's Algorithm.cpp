#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
const int K = 700;
const int N = 1e7 + 5;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> mp;

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = c;
            a[i] = c;
            c++;
        }
        else
            a[i] = mp[a[i]];
    }

    auto cmp = [&](ar<int, 3> &a, ar<int, 3> &b)
    {
        auto [l1, r1, i1] = a;
        auto [l2, r2, i2] = b;
        if (l1 / K == l2 / K)
            return r1 < r2;
        else
            return l1 / K < l2 / K;
    };

    vector<ar<int, 3>> qs;

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        qs.push_back({a, b, i});
    }
    vector<int> ans(q + 1);
    int cur = 0;
    vector<int> cnt(n + 1);

    function<void(int &)> Add = [&](int &i)
    {
        int x = a[i];
        cnt[x]++;
        if (cnt[x] == 1)
            cur++;
    };

    function<void(int &)> Remove = [&](int &i)
    {
        int x = a[i];
        cnt[x]--;
        if (cnt[x] == 0)
            cur--;
    };

    sort(qs.begin(), qs.end(), cmp);
    int l = 0, r = -1;

    for (auto &[L, R, i] : qs)
    {
        while (r < R)
        {
            r++;
            Add(r);
        }
        while (r > R)
        {
            Remove(r);
            r--;
        }
        while (l < L)
        {
            Remove(l);
            l++;
        }
        while (l > L)
        {
            l--;
            Add(l);
        }
        ans[i] = cur;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}