#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }

    long long a, b;
    while (q--)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << (a != 0 ? nums[b] - nums[a - 1] : nums[b]) << endl;
    }
    return 0;
}