#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 5;

class ST
{

    int n;
    vector<int> st;
    vector<int> a;

public:
    ST(vector<int> &b)
    {

        this->a = b;
        this->n = b.size();
        st.resize(4 * n + 5);
        build(0, 0, n - 1);
    }

    void build(int si, int l, int r)
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

    int query(int si, int l, int r, int ql, int qr)
    {

        if (l >= ql && r <= qr)
            return st[si];

        if (qr < l || ql > r)
            return 0;

        int m = (l + r) / 2;

        int left = query(2 * si + 1, l, m, ql, qr);
        int right = query(2 * si + 2, m + 1, r, ql, qr);

        return left + right;
    };

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

int32_t main()
{

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ST st(a);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << i << " " << j << " " << st.query(i, j) << "\n";
        }
    }
}