#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;

    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int price = prices[i];
        for (int cost = x; cost >= price; cost--)
        {
            dp[cost] = max(dp[cost], dp[cost - price] + page);
        }
    }

    int ans = 0;
    for (int p : dp)
    {
        ans = max(ans, p);
    }

    cout << ans << endl;
    return 0;
}
