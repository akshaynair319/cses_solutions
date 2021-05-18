#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<long long> &tree, vector<long long> &arr, int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(tree, arr, start, mid, 2 * node);
    buildTree(tree, arr, mid + 1, end, 2 * node + 1);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    return;
}

void update(vector<long long> &tree, vector<long long> &arr, int start, int end, int node, long long val, int idx)
{
    if (start == end)
    {
        tree[node] = val;
        arr[start] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx > mid)
    {
        update(tree, arr, mid + 1, end, node * 2 + 1, val, idx);
    }
    else
    {
        update(tree, arr, start, mid, node * 2, val, idx);
    }

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    return;
}

long long query(vector<long long> &tree, int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return LLONG_MAX;
    if (start >= left && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    long long ans1 = query(tree, start, mid, 2 * node, left, right);
    long long ans2 = query(tree, mid + 1, end, 2 * node + 1, left, right);
    return min(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;

    int size = 1;
    while (size < n)
    {
        size *= 2;
    }
    vector<long long> tree(4 * n + 1, LLONG_MAX);
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    buildTree(tree, nums, 0, n - 1, 1);

    int type, a, b;
    while (q--)
    {
        cin >> type >> a >> b;
        if (type == 1)
        {
            a--;
            update(tree, nums, 0, n - 1, 1, b, a);
        }
        else
        {
            a--;
            b--;
            cout << query(tree, 0, n - 1, 1, a, b) << endl;
        }
    }
    return 0;
}