#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int dif = abs(a - b);
        int p = 1;
        while (2 * p <= dif) 
                p *= 2;
        if (dif == p)
            cout << 1 << '\n';
        else {
            cout << abs(dif - p) + 1 << '\n';
        }
        // NOT DONE
    }
}