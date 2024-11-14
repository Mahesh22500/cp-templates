#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> st;

    for (int i = 0; i < n; i++)
    {

        st.insert(i);
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++)
    {
        int c, l, r;
        cin >> c >> l >> r;
        queries[i] = {c, l, r};
    }

    auto calc = [&](int n)
    {
        int cnt = 0;

        while (n)
        {
            n /= 10;
            cnt++;
        }

        return cnt;
    };

    vector<int>res;

    for (auto q : queries)
    {
        int c = q[0], l = q[1], r = q[2];
        l--, r--;

        if (c == 1)
        {

            while (st.size())
            {
                auto it = st.lower_bound(l);
                if (it == st.end())
                    break;
                int l1 = *it;
                if (l1 > r)
                    break;
                int x = a[l1];
                a[l1] = calc(x);
                if (a[l1] == 1)
                    st.erase(l1);
                l = l1 + 1;
            }
        }
        else
        {

            int ans = 0;
            int tot = r - l + 1;

            int cnt = 0;

            while (st.size())
            {
                auto it = st.lower_bound(l);
                if (it == st.end())
                    break;
                int l1 = *it;
                if (l1 > r)
                    break;
                cnt++;
                ans += a[l1];
                l = l1 + 1;
            }

            int ones = tot - cnt;
            ans += ones;
            res.push_back(ans);
            // cout << ans << "\n";
        }
    }

    for(auto x:res)
    cout<<x<<" ";
}