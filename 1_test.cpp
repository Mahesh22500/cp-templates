#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 700;
const int N = 2e5 + 5;
const int M = 1e9 + 7;

struct TrieNode
{
    TrieNode *child[26];

    int cnt;

    TrieNode()
    {
        for (auto &c : child)
            c = nullptr;
        cnt = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s, int f)
    {
        auto p = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            auto c = s[i] - 'a';
            if (!p->child[c])
            {
                p->child[c] = new TrieNode();
            }
            p = p->child[c];
            p->cnt = p->cnt + f;
        }
    }

    int query(string s)
    {
        auto p = root;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            auto c = s[i] - 'a';
            if (!p->child[c])
            {

                return 0;
            }
            p = p->child[c];
        }

        return p->cnt;
    }
};

int32_t main()
{

    int n;
    cin >> n;
    Trie trie;

    while (n--)
    {
        char op;
        cin >> op;

        string s;
        cin >> s;

        if (op == 'I')
        {
            int f;
            cin >> f;

            trie.insert(s, f);
        }
        else if (op == 'Q')
        {

            int res = trie.query(s);
            cout << res << "\n";
        }
        else
        {
            int f;
            cin >> f;
            int cur = trie.query(s);
            trie.insert(s, f - cur);
        }
    }
}