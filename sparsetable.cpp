#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
const int M = 1e9 + 7;
const int N = 3e5 + 5;

class SparseTable
{

    vector<int> a;
    int n;
    vector<vector<int>> st;

    public:

    SparseTable(vector<int> &b)
    {
        int n = b.size();
        this->n = n;
        a = b;
        st.resize(n);

        for (int i = 0; i < n; i++)
            st[i].resize(21);

        build();
    }

    void build()
    {

        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int k = i + (1 << j) - 1;
                if (k >= n)
                    continue;

                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int d = r - l + 1;
        int k = floor(log2(d));

        int res = min(st[l][k], st[r - (1 << k) + 1][k]);
        return res;
    }
};

int32_t
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    SparseTable st(a);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int res = st.query(i, j);
            cout << i << " " << j << " " << res << "\n";
        }
    }
}