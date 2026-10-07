#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

// Build Segment Tree
void build(int node, int l, int r, vector<int>& arr)
{
    if (l == r)
    {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * node + 1, l, mid, arr);
    build(2 * node + 2, mid + 1, r, arr);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

// Range Sum Query
int query(int node, int l, int r, int ql, int qr)
{
    // No Overlap
    if (r < ql || l > qr)
        return 0;

    // Complete Overlap
    if (l >= ql && r <= qr)
        return tree[node];

    // Partial Overlap
    int mid = (l + r) / 2;

    int leftSum = query(2 * node + 1, l, mid, ql, qr);
    int rightSum = query(2 * node + 2, mid + 1, r, ql, qr);

    return leftSum + rightSum;
}

// Point Update
void update(int node, int l, int r, int index, int value)
{
    if (l == r)
    {
        tree[node] = value;
        return;
    }

    int mid = (l + r) / 2;

    if (index <= mid)
        update(2 * node + 1, l, mid, index, value);
    else
        update(2 * node + 2, mid + 1, r, index, value);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int main()
{
    vector<int> arr = {2, 1, 5, 3, 4, 7, 6, 8};

    int n = arr.size();

    tree.resize(4 * n);

    build(0, 0, n - 1, arr);

    cout << "Range Sum (0 to 5): "
         << query(0, 0, n - 1, 0, 5) << endl;

    update(0, 0, n - 1, 2, 10);

    cout << "Range Sum (0 to 5) after update: "
         << query(0, 0, n - 1, 0, 5) << endl;

    return 0;
}
