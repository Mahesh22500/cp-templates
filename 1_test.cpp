#include <bits/stdc++.h>
using namespace std;
#define int long long

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

			// less than

			int cnt = lower_bound(st[si].begin(), st[si].end(), x) - st[si].begin();

			// greater than or equal to

			return (r - l + 1 - cnt);
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


vector<int> getCacheSize(vector<vector<int>>data,vector<int>queries){

	int n = data.size();

	int q = queries.size();

	vector<pair<int,int>>v(n);

	for(int i=0;i<n;i++){
		v[i] = {data[i][0],data[i][0]+data[i][1]};
	}


	sort(v.begin(),v.end());

	vector<int> l(n), r(n);

	for (int i = 0; i < n; i++)
	{
		l[i] = v[i].first;
		r[i] = v[i].second;
	}

	vector<int> ans;

	MergeSortTree st(r);

	for(int i=0;i<q;i++)
	{

		int x = queries[i];

		int L = upper_bound(l.begin(), l.end(), x) - l.begin();

		if (L == 0)
		{
			ans.push_back(0);
			continue;
		}

		L--;

		int res = st.query(0, L, x);

		ans.push_back(res);
	}


	return ans;

	
}

int32_t main()
{

	int n;
	cin >> n;

	int q;
	cin >> q;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
	{

		int l, x;
		cin >> l >> x;

		v[i] = {l, l + x};
	}

	sort(v.begin(), v.end());

	vector<int> l(n), r(n);

	for (int i = 0; i < n; i++)
	{
		l[i] = v[i].first;
		r[i] = v[i].second;
	}

	vector<int> ans;

	MergeSortTree st(r);

	while (q--)
	{

		int x;
		cin >> x;

		int L = upper_bound(l.begin(), l.end(), x) - l.begin();

		if (L == 0)
		{
			ans.push_back(0);
			continue;
		}

		L--;

		int res = st.query(0, L, x);

		ans.push_back(res);
	}

	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
}
