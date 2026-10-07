#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int> &arr, int l, int m, int h)
{
    int sum = 0, leftSum = INT_MIN;

    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSum(vector<int> &arr, int l, int h)
{
    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    int left = maxSum(arr, l, m);
    int right = maxSum(arr, m + 1, h);
    int cross = maxCrossingSum(arr, l, m, h);

    return max({left, right, cross});
}

int maxSubArraySum(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
        return 0;

    return maxSum(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 7};

    cout << maxSubArraySum(arr) << endl;

    return 0;
}
