#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;
const int N = 2e5 + 5;

struct Node
{
	Node *links[26];
	int cnt;
};

class Trie
{

	Node *root = new Node();

public:
	void insert(string &s)
	{

		Node *node = root;

		for (int i = 0; i < s.size(); i++)
		{
			if (node->links[s[i] - 'a'] == NULL)
			{
				node->links[s[i] - 'a'] = new Node();
			}

			node = node->links[s[i] - 'a'];
			node->cnt++;
		}
	}

	void remove(string &s)
	{

		Node *node = root;

		for (int i = 0; i < s.size(); i++)
		{
			node = node->links[s[i] - 'a'];
			node->cnt--;
		}
	}

	int query(string &s)
	{
		Node *node = root;

		int len0 = 0;
		int cnt0 = 0;
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (node->links[s[i] - 'a'] != NULL)
			{
				node = node->links[s[i] - 'a'];
				int len = i + 1;
				int cnt = node->cnt;
				res += len * cnt - len0 * cnt;
				// cout << len << " " << cnt << "\n";
				len0 = len;
				cnt0 = cnt;
			}
			else
				break;
		}

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

	vector<string> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	Trie trie;

	for (auto &s : v)
	{
		auto r = s;
		reverse(r.begin(), r.end());
		trie.insert(r);
	}

    	int res = 0;

	for (auto &s : v)
	{

		int cur = trie.query(s);

		res += cur;
	}

	int sum = 0;

	for (auto &s : v)
	{
		int len = s.size();
		sum += len;
	}

	int ans = 2 * n * sum - 2 * res;

	cout << ans << "\n";
}
