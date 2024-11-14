#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
const int M = 1e9 + 7;
const int N = 3e5 + 5;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> st(4 * n + 5), lazy(4 * n + 5);

    function<void(int, int, int)> build = [&](int si, int l, int r)
    {
        if (l == r)
        {
            st[si] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * si + 1, l, m);
        build(2 * si + 2, m + 1, r);
        st[si] = st[2 * si + 1] + st[2 * si + 2];
    };

    function<void(int, int, int, int, int, int)> update = [&](int si, int l, int r, int ql, int qr, int x)
    {
        if (lazy[si])
        {
            int n = (r - l) + 1;
            int x = lazy[si];
            st[si] += n * x;

            if (l != r)
            {
                lazy[2 * si + 1] += x;
                lazy[2 * si + 2] += x;
            }
            lazy[si] = 0;
        }
        if (l > qr || r < ql)
            return;

        if (l >= ql && r <= qr)
        {
            int n = (r - l) + 1;

            st[si] += n * x;

            if (l != r)
            {
                lazy[2 * si + 1] += x;
                lazy[2 * si + 2] += x;
                return;
            }
        }

            int m = (l + r) / 2;

            update(2 * si + 1, l, m, ql, qr, x);
            update(2 * si + 2, m + 1, r, ql, qr, x);

            st[si] = st[2 * si + 1] + st[2 * si + 2];
        };

        function<int(int, int, int, int, int)> query = [&](int si, int l, int r, int ql, int qr)
        {
            if (lazy[si])
            {
                int n = (r - l) + 1;
                int x = lazy[si];
                st[si] += n * x;

                if (l != r)
                {
                    lazy[2 * si + 1] += x;
                    lazy[2 * si + 2] += x;
                }
                lazy[si] = 0;
            }
            if (l > qr || r < ql)
            {
                return 0LL;
            }
            if (l >= ql && r <= qr)
                return st[si];

            int m = (l + r) / 2;

            int left = query(2 * si + 1, l, m, ql, qr);
            int right = query(2 * si + 2, m + 1, r, ql, qr);

            return left + right;
        };
        build(0, 0, n - 1);

        while (q--)
        {
            int c;
            cin >> c;
            if (c == 1)
            {
                int l, r, u;
                cin >> l >> r >> u;
                l--, r--;
                update(0, 0, n - 1, l, r, u);
            }
            else
            {
                int k;
                cin >> k;
                k--;

                int ans = query(0, 0, n - 1, k, k);
                cout << ans << "\n";
            }
        }
    }
