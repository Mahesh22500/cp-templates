#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 998244353;
const int N = 4e4 + 5;

class MergeSortTree
{

	int n;
	vector<int> a;

	vector<vector<int>> st;

public:
	MergeSortTree(vector<int> &b)
	{

		this->n = b.size();

		this->a = b;

		st.resize(4 * n + 5);

		build(0, 0, n - 1);
	}

	void build(int si, int l, int r)
	{

		if (l == r)
		{
			st[si].push_back(a[l]);
			return;
		}

		int m = (l + r) / 2;

		build(2 * si + 1, l, m);
		build(2 * si + 2, m + 1, r);

		auto &a = st[2 * si + 1];
		auto &b = st[2 * si + 2];

		vector<int> c;

		int i = 0, j = 0;

		while (i < a.size() && j < b.size())
		{
			if (a[i] < b[j])
				c.push_back(a[i++]);
			else
				c.push_back(b[j++]);
		}

		while (i < a.size())
			c.push_back(a[i++]);

		while (j < b.size())
			c.push_back(b[j++]);

		st[si] = c;
	}

	int query(int si, int l, int r, int ql, int qr, int x)
	{

		if (l >= ql && r <= qr)
		{

			int res = 0;

			res += upper_bound(st[si].begin(), st[si].end(), x) - st[si].begin();
			return res;
		}

		if (l > qr || r < ql)
			return 0LL;

		int m = (l + r) / 2;

		int left = query(2 * si + 1, l, m, ql, qr, x);
		int right = query(2 * si + 2, m + 1, r, ql, qr, x);

		return left + right;
	}

	int query(int l, int r, int x)
	{
		return query(0, 0, n - 1, l, r, x);
	}
};

int32_t
main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;

	while (tt--)
	{

		int a, b, n, m;
		cin >> a >> b >> n >> m;

		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;

			v.push_back({x, y});
		}

		sort(v.begin(), v.end());

		vector<int> A, B;

		for (auto [x, y] : v)
			A.push_back(x), B.push_back(y);

		vector<vector<int>> queries;

		int l1 = 1, l2 = a, r1 = 1, r2 = b;

		for (int i = 0; i < m; i++)
		{

			char c;
			cin >> c;

			int k;
			cin >> k;

			if (c == 'U')
			{
				queries.push_back({l1, l1 + k - 1, r1, r2});
				l1 += k;
			}
			else if (c == 'D')
			{
				queries.push_back({l2 - k + 1, l2, r1, r2});
				l2 -= k;
			}
			else if (c == 'L')
			{
				queries.push_back({l1, l2, r1, r1 + k - 1});
				r1 += k;
			}
			else
			{
				queries.push_back({l1, l2, r2 - k + 1, r2});
				r2 -= k;
			}
		}

		vector<int> ans;

		MergeSortTree mst(B);

		for (auto &q : queries)
		{

			int l1 = q[0], l2 = q[1], r1 = q[2], r2 = q[3];
			// cout << "ranges\n";
			// cout << l1 << " " << l2 << " " << r1 << " " << r2 << "\n";

			int L1 = lower_bound(A.begin(), A.end(), l1) - A.begin();
			int L2 = upper_bound(A.begin(), A.end(), l2) - A.begin();
			L2--;

			if (L1 > L2)
			{
				ans.push_back(0);
				continue;
			}
			// cout << "r2:" << r2 << "\n";

			// cout << mst.query(L1, L2, r2) << "\n";
			// cout << "r1:" << r1 << "\n";
			// cout << mst.query(L1, L2, r1 - 1) << "\n";
			int res = mst.query(L1, L2, r2) - mst.query(L1, L2, r1 - 1);
			// cout << "res:" << res << "\n";

			ans.push_back(res);
		}

		int p1 = 0, p2 = 0;

		for (int i = 0; i < m; i++)
		{
			int p = ans[i];

			// cout << p << "\n";
			if (i % 2 == 0)
				p1 += p;
			else
				p2 += p;
		}

		cout << p1 << " " << p2 << "\n";
	}
}