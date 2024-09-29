#include <bits/stdc++.h>
using namespace std;

// se da un vector de numere
// vrem un vector cu pozitiile care nu au niciun numar mai mare inainte
// e.g.: [3, 4, 6, 2, 1, 7]
// output = [0, 1, 2, 5]

// i = 0
// while(stack.top < v[i]) -> stack.pop
// if (stack.empty) -> ans.push_back()

// [3, 3, 2]
// [0]

vector<int> FindPos(vector<int> &v)
{
    vector<int> ans;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!ans.empty() && v[ans.back()] > v[i])
            ans.pop_back();
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> FindPos_Second(vector<int> &v)
{
    int mxm = -1E9;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (mxm < v[i])
        {
            ans.push_back(i);
            mxm = v[i];
        }
    }
    return ans;
}

void Test_1()
{
    vector<int> v = {3, 4, 6, 2, 1, 7};
    vector<int> ans = FindPos_Second(v);
    for (auto i : ans)
        cerr << i << " ";
    cerr << '\n';
    assert(ans == vector<int>({0, 1, 2, 5}));
}

void Test_2()
{
    vector<int> v = {1, 1, 1, 1};
    vector<int> ans = FindPos_Second(v);
    assert(ans == vector<int>({0}));
}

int main()
{
    Test_1();
    Test_2();
}