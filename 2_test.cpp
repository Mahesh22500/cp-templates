#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    const int N = 1e5 + 5;

    vector<int> cnt(N);

    for (auto x : a)
        cnt[x]++;

    vector<long long> dp(N);

    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {
        dp[i] = (dp[i - 1] + 1) * cnt[i];
    }

    long long ans = 0;

    for (int i = 1; i < N; i++)
        ans += dp[i];

    cout << ans << "\n";
}


function getCatcheSize(ve)