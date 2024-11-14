#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = 1e18 + 5;

class ST
{

	vector<int> a;
	vector<int> st;
	int n;

	int c;

public:
	ST(vector<int> &a, int c)
	{
		this->a = a;
		this->c = c;
		int n = a.size();
		this->n = n;
		st.resize(4 * n + 5);
		build(0, 0, n - 1);
	}

	int combine(int a, int b)
	{
		if (c == 1)
			return min(a, b);
		else
			return max(a, b);
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

		st[si] = combine(st[2 * si + 1], st[2 * si + 2]);
	};

	void update(int si, int l, int r, int qi, int x)
	{
		if (l == r)
		{

			st[si] = x;
			return;
		}
		int m = (l + r) / 2;
		if (qi <= m)
			update(2 * si + 1, l, m, qi, x);
		else
			update(2 * si + 2, m + 1, r, qi, x);
		st[si] = combine(st[2 * si + 1], st[2 * si + 2]);
	};

	int queryMax(int si, int l, int r, int ql, int qr)
	{
		if (l >= ql && r <= qr)
			return st[si];

		if (l > qr || r < ql)
			return -1;

		int m = (l + r) / 2;
		int op1 = queryMax(2 * si + 1, l, m, ql, qr);
		int op2 = queryMax(2 * si + 2, m + 1, r, ql, qr);
		return combine(op1, op2);
	};

	int queryMin(int si, int l, int r, int ql, int qr)
	{
		if (l >= ql && r <= qr)
			return st[si];

		if (l > qr || r < ql)
			return (long long)(1e18);\

		int m = (l + r) / 2;
		int op1 = queryMin(2 * si + 1, l, m, ql, qr);
		int op2 = queryMin(2 * si + 2, m + 1, r, ql, qr);
		return combine(op1, op2);
	};

	int queryMin(int l, int r)
	{
		return queryMin(0, 0, n - 1, l, r);
	}

	int queryMax(int l, int r)
	{
		return queryMax(0, 0, n - 1, l, r);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;

	while (tt--)
	{

		int n;
		cin >> n;

		vector<int> a(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		ST st1(a, 1);
		ST st2(a, 2);

		vector<vector<int>> pos(n + 1);

		for (int i = 0; i < n; i++)
		{
			pos[a[i]].push_back(i);
		}

		vector<int> last(n + 1, -1);

		for (int i = 1; i <= n; i++)
		{
			if (pos[i].size() == 0)
				continue;

			last[i] = pos[i].back();
		}

		set<int> st;

		for (int i = 1; i <= n; i++)
		{
			if (last[i] != -1)
				st.insert(last[i]);
		}

		int l = 0;

		vector<int> ans;

		int k = st.size();

		for (int i = 0; i < k; i++)
		{

			if (i % 2 == 0)
			{

				int r = *st.begin();

				int mx = st2.queryMax(l, r);

				ans.push_back(mx);
				st.erase(last[mx]);
				auto it = lower_bound(pos[mx].begin(), pos[mx].end(), l);
				l = (*it) + 1;

				for (auto x : pos[mx])
				{
					st2.update(0, 0, n - 1, x, -1);
					st1.update(0, 0, n - 1, x, 1e18);
				}
			}
			else
			{
				int r = *st.begin();
				int mn = st1.queryMin(l, r);

				ans.push_back(mn);
				st.erase(last[mn]);
				auto it = lower_bound(pos[mn].begin(), pos[mn].end(), l);
				l = (*it) + 1;

				for (auto x : pos[mn])
				{
					st1.update(0, 0, n - 1, x, 1e18);
					st2.update(0, 0, n - 1, x, -1);
				}
			}
		}

		cout << ans.size() << "\n";

		for (auto x : ans)
			cout << x << " ";
		cout << "\n";
	}
}
