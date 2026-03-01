#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long W;
    cout << "Name: Mistry Nishk Nileshkumar\nRegistration Number: 24BCE5236\n";
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> W;
    struct Item
    {
        long long w;
        long long v;
        double r;
    };
    vector<Item> items;
    long long zeroValueSum = 0;
    cout << "Enter value and weight: (v w)\n";
    for (int i = 0; i < n; i++)
    {
        long long w, v;
        cin >> v >> w;
        if (w == 0)
        {
            zeroValueSum += v;
        }
        else
        {
            items.push_back({w, v, (double)v / (double)w});
        }
    }
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         {
if(a.r!=b.r) return a.r>b.r;
if(a.v!=b.v) return a.v>b.v;
return a.w<b.w; });
    double rem = (double)W;
    double fracTotal = (double)zeroValueSum;
    for (auto &it : items)
    {
        if (rem <= 0)
            break;
        double take = min(rem, (double)it.w);
        fracTotal += take * it.r;
        rem -= take;
    }
    vector<long long> dp(W + 1, 0);
    for (auto &it : items)
    {
        long long wt = it.w;
        long long val = (long long)it.r * 0 + (long long)llround(it.r * 0);
        val = (long long)(it.r * it.w + 0.5);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)llround(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)(it.r * it.w);
        val = (long long)llround(it.r * it.w);
        for (long long cap = W; cap >= wt; --cap)
        {
            dp[cap] = max(dp[cap], dp[cap - wt] + val);
        }
    }
    long long bestDP = dp[W] + zeroValueSum;
    cout << "Maximum Value: " << bestDP;
    return 0;
}