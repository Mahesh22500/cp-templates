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
    vector < vector<int> st;

    SparseTable(vector<int> &b)
    {
        int n = b.size();
        this->= n;
        a = b;
        st.resize(n);

        for (int i = 0; i < n; i++)
            st[i].resize(21);

            
        build();
    }

    void build()
    {

        for(int i=0;i<n;i++)
        st[i][0]=a[i];


        for(int j=1;j<n;j++){
            int
        }
    }
}

int32_t
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> st(n, vector<int>(21));

    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    for (int k = 1; k <= 20; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            st[i][k] = (st[i][k - 1] + st[i + (1 << (k - 1))][k - 1]);
        }
    }

    while (q--)
    {
        int a, b;   
        cin >> a >> b;
        a--, b--;
        int dx = (b - a + 1);
        int ans = 0;
        for (int i = 20; i >= 0; i--)
        {
            if (dx & (1 << i))
            {
                ans += st[a][i];
                a += (1 << i);
            }
        }
        cout << ans << "\n";
    }
}