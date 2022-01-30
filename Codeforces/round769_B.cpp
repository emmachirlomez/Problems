#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p = 1;
        int c = 0;
        while (2 * p <= n - 1) 
            p *= 2, c++;
        for (int i = 1; i < p; i++)
            cout << i << " ";
        cout << 0 << " " << p << " ";
        for (int i = p + 1; i < n; i++)
            cout << i << " ";
        cout << '\n';
    }
    return 0;
}
