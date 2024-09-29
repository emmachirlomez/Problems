#include <bits/stdc++.h>
using namespace std;

/**
 * We are looking for the maximal 0 <= x < v_max with criteria(x) == true.
 * criteria(x) -> (criteria(x - 1) == true).
 */
int BinarySearch(int v_max, function<bool(int)> criteria)
{
    int ans = -1;
    int left = 0, right = v_max - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (criteria(middle))
        {
            ans = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return ans;
}

/**
 * We are looking for the maximal 0 <= x < v_max with criteria(x) == true.
 * criteria(x) -> (criteria(x - 1) == true).
 */
int BinarySearchSecondWay(int v_max, function<bool(int)> criteria)
{
    int ans = -1;
    for (int step = (1 << 20); step; step /= 2)
        if (ans + step < v_max && criteria(ans + step))
            ans += step;
    return ans;
}

/**
 * Returns the index of the greatest number in v, smaller or rqual to target.
 */
int FindIndex(vector<int> v, int target)
{
    int ans = -1;
    int step = 1 << 20;

    for (int step = 1 << 20; step != 0; step /= 2)
        if (ans + step < v.size() && v[ans + step] <= target)
            ans += step;

    while (step != 0)
    {
        if (ans + step < v.size() && v[ans + step] <= target)
            ans += step;
        step /= 2;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());
    while (true)
    {
        int x;
        cin >> x;
        int index = BinarySearch(n, [&](int i)
                                 { return v[i] <= x; });
        cout << v[index] << '\n';
    }
}