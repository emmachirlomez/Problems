// C++ 20 on Ubuntu

#include <bits/stdc++.h>
using namespace std;

// we define a "Number" as a vector of integer 
using Number = vector <int>;

ostream& operator<<(ostream& out, const Number& nr) {
    for (int i = (int)nr.size() - 1; i >= 0; i--)
        out << nr[i];
    return out;
}

// Task 1

/**
 * We increment x by one.
 * We search for the first digit not equal to 2, which we increase by 1
 * and set all of the previous bits to 0.
 */
Number S(const Number& x) 
{
    Number x_plus_1 = x;
    x_plus_1.push_back(0);

    int bit_to_add = 0;
    while(x_plus_1[bit_to_add] == 2) {
        x_plus_1[bit_to_add] = 0;
        bit_to_add++;
    }
    x_plus_1[bit_to_add]++;
    if (x_plus_1.back() == 0)
        x_plus_1.pop_back();
    
    return x_plus_1;
}


// Task 2

/**
 * If after removing the extra 0, we have a different length, we just return 
 * the smallest one.
 * If not, we look for the first mismatch.
 */
bool L(Number n1, Number n2)
{
    while (!n1.empty() && n1.back() == 0)
        n1.pop_back();
    while (!n2.empty() && n2.back() == 0)
        n2.pop_back();
    
    if (n1.size() != n2.size())
        return n1.size() < n2.size();
    
    for (int i = n1.size() - 1; i >= 0; i--)
        if (n1[i] != n2[i])
            return n1[i] < n2[i];

    return 1;
}


// Task 3

/**
 * We just look for the minimal value of each bit ;)
 */
Number M(Number nr1, Number nr2)
{
    while (nr1.size() != nr2.size())
        if (nr1.size() < nr2.size())
            nr1.push_back(0);
        else
            nr2.push_back(0);

    Number ans;
    for (int i = 0; i < nr1.size(); i++)
        ans.push_back(min(nr1[i], nr2[i]));

    while (!ans.empty() && ans.back() == 0)
        ans.pop_back();

    return ans;
}


// Task 4

/**
 * We brute-force all the numbers between nr1 and nr2, and use the M function.
 */
Number f(Number nr1, Number nr2)
{
    Number ans = nr1;
    while (L(nr1, nr2)) {
        ans = M(ans, nr1);
        nr1 = S(nr1);
    }

    return ans;
}


// Task 5

/**
 * We can see that when a bit is increased, all the previous bits are set to 0, which will also 
 * appear in the final min.
 * As such, we can just find the last bit that will get increased, set all of the bits before it to 0
 * and all of the bits after it to their value in nr1 or nr2.
 */
Number f_eff(Number nr1, Number nr2)
{
    if (nr1 == nr2)
        return nr1;

    // making both of them have the same size
    while (nr1.size() != nr2.size())
        if (nr1.size() < nr2.size())
            nr1.push_back(0);
        else
            nr2.push_back(0);
    
    int position_last_diff;
    for (int i = 0; i < nr1.size(); i++)
        if (nr1[i] != nr2[i])
            position_last_diff = i;
    
    Number ans;
    for (int i = 0; i < position_last_diff; i++)
        ans.push_back(0);

    for (int i = position_last_diff; i < (int)nr1.size(); i++)
        ans.push_back(nr1[i]);


    return ans;
}

int main()
{
    Number nr = { 1, 0, 2 };
    cout << "Task 1:\n";
    cout << nr << ' ' << S(nr) << ' ' << S(S(nr)) << "\n\n";

    Number nr1 = { 2, 0 ,1 };
    Number nr2 = { 1, 1 ,1 };
    cout << "Task 2:\n";
    cout << nr1 << ' ' << nr2 << ' ' << L(nr1, nr2) << "\n\n";

    cout << "Task 3:\n";
    cout << nr1 << ' ' << nr2 << ' ' << M(nr1, nr2) << "\n\n";

    cout << "Task 4:\n";
    cout << nr1 << ' ' << nr2 << ' ' << f(nr1, nr2) << "\n\n";

    cout << "Task 5:\n";
    cout << nr1 << ' ' << nr2 << ' ' << f_eff(nr1, nr2) << "\n\n";

}

