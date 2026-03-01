#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct SubarrayData
{
    int sum;
    int start;
    int end;
};
SubarrayData maxCrossingSum(vector<int> &nums, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int max_left = m;
    for (int i = m; i >= l; i--)
    {
        sum += nums[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    int max_right = m + 1;
    for (int i = m + 1; i <= h; i++)
    {
        sum += nums[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    return {left_sum + right_sum, max_left, max_right};
}
SubarrayData maxSubArraySum(vector<int> &nums, int l, int h)
{
    if (l == h)
        return {nums[l], l, h};
    int m = l + (h - l) / 2;
    SubarrayData left = maxSubArraySum(nums, l, m);
    SubarrayData right = maxSubArraySum(nums, m + 1, h);
    SubarrayData cross = maxCrossingSum(nums, l, m, h);
    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    return cross;
}
int main()
{
    cout << "Name: Mistry Nishk Nileshkumar\nRegistration Number: 24BCE5236\n";
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    SubarrayData result = maxSubArraySum(nums, 0, n - 1);
    cout << "Maximum Sum: " << result.sum << endl;
    cout << "The Subarray is: ";
    for (int i = result.start; i <= result.end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}